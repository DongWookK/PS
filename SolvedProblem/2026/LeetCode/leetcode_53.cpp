class Solution {
public:
    int maxCrossingSum(const std::vector<int>& nums, int left, int mid, int right) {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            left_sum = std::max(left_sum, sum);
        }

        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            right_sum = std::max(right_sum, sum);
        }

        return left_sum + right_sum;
    }

    int maxSubArrayHelper(const std::vector<int>& nums, int left, int right) {
        if (left == right) return nums[left]; // 원소가 1개인 기저 사례

        int mid = left + (right - left) / 2;

        int left_max = maxSubArrayHelper(nums, left, mid);          // 1번 경우
        int right_max = maxSubArrayHelper(nums, mid + 1, right);    // 2번 경우
        int cross_max = maxCrossingSum(nums, left, mid, right);     // 3번 경우

        return std::max({ left_max, right_max, cross_max });
    }

    int maxSubArray(std::vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};