class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;

        for (int i = 0; i < 26; i++) {
            char c = 'A' + i;
            map<char, int> cnt;
            int l = 0;
            for (int r = 0; r < n; r++) {
                cnt[s[r]]++;
                int x = r - l + 1 - cnt[c];
                if (x > k) {
                    cnt[s[l]]--;
                    l++;
                } else res = max(r - l + 1, res);
            }
        }

        return res;
    }
};
