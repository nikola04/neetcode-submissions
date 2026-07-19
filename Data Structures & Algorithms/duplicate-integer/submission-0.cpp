class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> has;
        for (int num : nums) {
            if (has.find(num) != has.end()) return true;
            has.emplace(num, true);
        }
        return false;
    }
};