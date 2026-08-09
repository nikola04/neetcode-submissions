class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, int>> pairs(n);

        for (int i { 0 }; i < n; ++i) {
            pairs[i] = { position[i], speed[i] };
        }
        std::sort(pairs.rbegin(), pairs.rend());

        // std::ranges::sort(std::views::zip(position, speed), std::greater{});
        int result { 0 };

        double last { -1 };
        int cnt { 0 };
        for (size_t i { 0 }; i < n; ++i) {
            double s { static_cast<double>(target - pairs[i].first) };
            double t { s / pairs[i].second };
            if (t > last) {
                last = t;
                if (cnt > 0) {
                    result++;
                    cnt = 0;
                }
            }

            cnt++;
        } 

        if (cnt > 0) result++;

        return result;
    }
};
