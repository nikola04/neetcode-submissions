class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<int, 26>, std::vector<std::string>> result_m;

        for (std::string str : strs) {
            std::array<int, 26> counts = {0};

            for (char c : str) {
                int x = c - 'a';

                counts[x]++;
            }

            result_m[counts].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& p : result_m) {
            result.push_back(p.second);
        }

        return result;
    }
};
