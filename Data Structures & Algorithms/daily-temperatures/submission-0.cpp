class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<int> idx_s, s;
        vector<int> result(n);

        for (int i {0}; i < n; ++i) {
            int t { temperatures[i] };
            while (!s.empty() && t > s.top()) {
                s.pop();
                int idx { idx_s.top() }; idx_s.pop();
                result[idx] = i - idx;
            }
            s.push(t);
            idx_s.push(i);
        }

        while(!s.empty()) {
            int idx = idx_s.top();

            result[idx] = 0;

            s.pop(); idx_s.pop();
        }

        return result;
    }
};
