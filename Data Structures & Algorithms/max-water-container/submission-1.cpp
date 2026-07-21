class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;

        int result = -1;
        while(l < r) {
            int w = r - l, h = min(heights[l], heights[r]);
            int surf = w * h;

            if (heights[l] < heights[r])
                l++;
            else r--;

            result = max(result, surf);
        }

        return result;
    }
};
