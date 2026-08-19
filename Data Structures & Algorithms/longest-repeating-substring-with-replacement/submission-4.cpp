class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;

        map<char, int> cnt;
        int l = 0;
        int maxf = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r]]++;
            maxf = max(cnt[s[r]], maxf);
            while (r - l + 1 - maxf > k) {
                cnt[s[l]]--;
                l++;
            } 

            res = max(r - l + 1, res);
        }

        return res;
    }
};
