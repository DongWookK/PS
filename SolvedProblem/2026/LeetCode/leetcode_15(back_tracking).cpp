class Solution {
public:
    void recursive_sum(const vector<int>& nums, int count_sum, int current_sum, int base_index, vector<int>& select_nums, vector<vector<int>>& results)
    {
        for (int i = base_index; i < nums.size(); ++i)
        {
            if (i > base_index && nums[i] == nums[i - 1]) continue;

            if (count_sum < 2)
            {
                int new_current_sum = current_sum + nums[i];
                auto new_select_nums = select_nums;
                new_select_nums.push_back(nums[i]);

                recursive_sum(nums, count_sum + 1, new_current_sum, i + 1, new_select_nums, results);
            }
            else
            {
                if (0 == (current_sum + nums[i]))
                {
                    results.push_back({ select_nums[0], select_nums[1], nums[i] });
                }
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> final_result{};

        for (int i = 0; i < (int)nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            vector<vector<int>> results{};
            vector<int> select_nums{ nums[i] };

            recursive_sum(nums, 1, nums[i], i + 1, select_nums, results);

            for (auto& triplet : results)
            {
                final_result.push_back(triplet);
            }
        }

        return final_result;
    }
};