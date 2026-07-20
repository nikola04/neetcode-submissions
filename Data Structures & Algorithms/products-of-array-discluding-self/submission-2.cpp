class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> b(n, 1);

        for (int i = 1; i < nums.size(); i++){
            f[i] = nums[i-1] * f[i-1];
            int j = n - 1 - i;
            b[j] = nums[j+1] * b[j+1];
        }

        vector<int> r(n);
        for (int i = 0; i < n; i++){
            r[i] = f[i] * b[i];
        }

        return r;
    }
};
