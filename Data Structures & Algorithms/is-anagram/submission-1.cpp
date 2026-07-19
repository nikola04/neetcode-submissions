class Solution {
public:
    static int getOrDefault(std::unordered_map<int, int>& m, int key, int defaultVal) {
        if (m.find(key) != m.end())
            return m.find(key)->second;

        return defaultVal;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<int, int> m;

        for (char c : s) {
            int key = c - '0';
            m[key] = getOrDefault(m, key, 0) + 1;
        }

        for (char c : t) {
            int key = c - '0';
            m[key] = getOrDefault(m, key, 0) - 1;
        }

        for (const auto& [key, value] : m) {
            if (value != 0) return false;
        }

        return true;
    } 
};
