class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;

        for (int n : nums)
            m[n]++;

        vector<vector<int>> freq(n+1);

        for (const auto& p : m) {
            freq[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int n : freq[i]) {
                result.push_back(n);

                if (result.size() >= k)
                    break;
            }
        }

        return result;
    }
};
