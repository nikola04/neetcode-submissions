class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];

        int result = 0;

        while (l < r) {
            if (maxL < maxR) {
                maxL = max(maxL, height[++l]);
                result += maxL - height[l];
            } else {
                maxR = max(maxR, height[--r]);
                result += maxR - height[r];
            }
        }

        return result;
    }
};
