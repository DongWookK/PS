class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 중복 값 건너뛰기
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                }
                else if (sum < 0) {
                    // 합이 0보다 작으면 더 큰 값이 필요하므로 left 오른쪽으로 이동
                    ++left;
                }
                else { // sum > 0
                    // 합이 0보다 크면 더 작은 값이 필요하므로 right 왼쪽으로 이동
                    --right;
                }
            }
        }

        return result;
    }
};