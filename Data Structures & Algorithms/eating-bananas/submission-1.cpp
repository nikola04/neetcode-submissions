class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, piles[i]);
        }

        int result = r;
        while(l < r) {
            int m = (r - l) / 2 + l;
            
            int t = 0;
            for (int i = 0; i < n; i++) {
                t += (piles[i] + m - 1) / m;
            }

            if (t > h) {
                l = m + 1;
            }else{
                result = min(result, m);
                r = m;
            }
        }

        return result;
    }
};
