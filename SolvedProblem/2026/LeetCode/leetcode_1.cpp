class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash_num;

        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];

            auto it = hash_num.find(diff);
            if (it != hash_num.end())
            {
                return { it->second, i };
            }

            hash_num[nums[i]] = i;
        }

        return {};
    }
};