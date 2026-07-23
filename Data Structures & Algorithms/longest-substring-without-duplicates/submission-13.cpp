class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> chars;

        int result = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (const auto& p { chars.find(s[i]) }; p != chars.end()) {
                last = max(p->second + 1, last);
            }

            chars[s[i]] = i;
            result = max(result, i - last + 1);
        }

        return result;
    }
};
