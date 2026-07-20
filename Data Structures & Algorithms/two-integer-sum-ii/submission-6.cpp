class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int s = numbers[l] + numbers[r];

            if (s < target)
                l++;
            else if (s > target)
                r--;
            else 
                return {l+1, r+1};
        }

        return {-1, -1};
    }
};
