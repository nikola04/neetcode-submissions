class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;

        for (int n : nums)
            m[n]++;

        priority_queue<pair<int, int>> pq;

        for (const auto& p : m) {
            pq.push({ p.second, p.first });
        }

        vector<int> result;
        for (int i = 0; i < k && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
