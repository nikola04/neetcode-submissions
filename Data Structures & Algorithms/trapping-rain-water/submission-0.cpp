class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int lm = height[l], rm = height[r];

        int result = 0;

        while (l < r) {
            if (lm < rm) {
                l++;
                lm = max(lm, height[l]);
                result += lm - height[l];
            } else {
                r--;
                rm = max(rm, height[r]);
                result += rm - height[r];
            }
        }

        return result;
    }
};
