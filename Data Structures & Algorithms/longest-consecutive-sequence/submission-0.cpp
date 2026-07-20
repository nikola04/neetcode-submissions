class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int res = 0;
        for (int n : nums) {
            int t = 1;

            int l = n, r = n;
            while (s.find(--l) != s.end())
                t++;

            while (s.find(++r) != s.end())
                t++;

            res = max(res, t);
        }

        return res;
    }
};
