class Solution {
public:

    string encode(vector<string>& strs) {
        string r;

        for (string s : strs) {
            r += to_string(s.length()) + "#" + s;
        }

        return r;
    }

    vector<string> decode(string s) {
        vector<string> r;
        int i = 0;

        int l = 0;
        bool has_l = false;
        while(i < s.length()) {
            char c = s[i++];
            if (c >= '0' && c <= '9')
                l = l * 10 + (c - '0');
            else if (c == '#') 
                has_l = true;

            if (has_l) {
                string t = "";
                while (i < s.length() && l > 0) {
                    t += s[i++];
                    l--;
                }
                r.push_back(t);
                has_l = false;
            }
        }

        return r;
    }
};
