#include "algorithm"
#include "functional"
#include "ranges"
#include "vector"
#include <iostream>

class Solution {
public:
  int carFleet(int target, std::vector<int> &position,
               std::vector<int> &speed) {
    int n = position.size();

    std::ranges::sort(std::ranges::views::zip(position, speed), std::greater{});
    int result{0};

    double last{-1};
    int cnt{0};
    for (size_t i{0}; i < n; ++i) {
      double s{static_cast<double>(target - position[i])};
      double t{s / speed[i]};
      if (t > last) {
        last = t;
        if (cnt > 0) {
          result++;
          cnt = 0;
        }
      }

      cnt++;
    }

    if (cnt > 0)
      result++;

    return result;
  }
};