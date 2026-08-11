class Solution {
public:
    int get_idx(char c) {
        return c - 'a';
    }
    bool check(std::array<int, 26>& arr) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        std::array<int, 26> freq { 0 };
        for (const auto& c : s1)
            freq[get_idx(c)]++;

        size_t w { s1.length() };
        int l { 0 };
        for (int r { 0 }; r < s2.length(); ++r) {
            if (r - l + 1 > w) {
                freq[get_idx(s2[l++])]++;
            }
            freq[get_idx(s2[r])]--;

            if (check(freq)) return true;
        }

        return false;
    }
};
