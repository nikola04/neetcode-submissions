class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int f = 1, b = 1;

        vector<int> r(n, 1);

        for (int i = 1; i < nums.size(); i++){
            f *= nums[i-1];
            r[i] *= f;
        }

        for (int i = n - 2; i >= 0; i--){
            b *= nums[i+1];
            r[i] *= b;
        }

        return r;
    }
};
