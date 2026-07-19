class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> has;

        for (int i = 0; i < nums.size(); i++) {
            const auto& p = has.find(target - nums[i]);
            if (p != has.end())
                return { p->second, i };

            has.emplace(nums[i], i);
        }

        return { -1, -1 };
    }
};
