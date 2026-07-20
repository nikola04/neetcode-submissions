class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        set<int> c;

        int res = 0;
        for (int n : nums) {
            if (c.find(n) != c.end()) continue;
            c.insert(n);

            int t = 1;
            int l = n, r = n;
            while (s.find(--l) != s.end()) {
               t++;
               c.insert(l);
            }

            while (s.find(++r) != s.end()) {
                t++;
                c.insert(r);
            }

            res = max(res, t);
        }

        return res;
    }
};
