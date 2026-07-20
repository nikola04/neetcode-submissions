class Solution {
public:
    static char onlyLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c + ('a' - 'A');

        return c;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;

        while (l < r) {
            int cl = onlyLower(s[l++]);
            int cr = onlyLower(s[r--]);

            while (!((cl >= 'a' && cl <= 'z') || (cl >= '0' && cl <= '9'))) {
                if (l >= n) {
                    cl = -1;
                    break;
                }
                cl = onlyLower(s[l++]);
            }

            while (!((cr >= 'a' && cr <= 'z') || (cr >= '0' && cr <= '9'))) {
                if (r < 0) {
                    cr = -1;
                    break;
                }
                cr = onlyLower(s[r--]);
            }

            cout << cl << endl;
            cout << cr << endl;

            if (cl != cr)
                return false;
        }

        return true;
    }
};
