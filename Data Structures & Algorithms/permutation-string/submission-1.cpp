class Solution {
public:
    int get_idx(char c) {
        return c - 'a';
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int matches { 0 };
        std::array<int, 26> freq { 0 };
        for (const auto& c : s1) {
            freq[get_idx(c)]++;
            matches++;
        }

        size_t w { s1.length() };
        int l { 0 };
        for (int r { 0 }; r < s2.length(); ++r) {
            if (r - l + 1 > w) {
                if (++freq[get_idx(s2[l])] > 0)
                    matches++;
                l++;
            }
            if(--freq[get_idx(s2[r])] >= 0) matches--;

            if (matches == 0) return true;
        }

        return false;
    }
};
