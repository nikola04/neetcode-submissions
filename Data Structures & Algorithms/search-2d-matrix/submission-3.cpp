class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            int mi = l + (r - l) / 2;
            int i = mi / m;
            int j = mi % m;

            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] < target)
                l = mi + 1;
            else {
                r = mi - 1;
            }
        }
        return false;
    }
};
