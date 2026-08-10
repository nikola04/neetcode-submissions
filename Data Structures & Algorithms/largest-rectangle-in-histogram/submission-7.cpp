class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t n { heights.size() };
        int result { 0 };

        std::stack<int> s {};
        for (int i { 0 }; i <= n; ++i) {
            while(!s.empty() && 
                (i == n || heights[i] <= heights[s.top()])) {
                    int h { heights[s.top()] };
                    s.pop();
                    int w { s.empty() ? i : (i - 1 - s.top()) };
                    result = std::max(result, w * h);
                }
            s.push(i);
        }

        return result;
    }
};
