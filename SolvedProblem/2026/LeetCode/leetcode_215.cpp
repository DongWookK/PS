class Solution {
public:
    void quick_select(int start_idx, int end_idx, vector<int>& list, int target_idx) {
        if (start_idx >= end_idx) return;

        int32_t random_pivot_idx = start_idx + (std::rand() % (end_idx - start_idx + 1));
        std::swap(list[start_idx], list[random_pivot_idx]);

        int key = list[start_idx];
        int left = start_idx - 1;
        int right = end_idx + 1;

        while (true) {
            do { ++left; } while (list[left] < key);
            do { --right; } while (list[right] > key);

            if (left >= right) break;
            std::swap(list[left], list[right]);
        }

        // target_idx가 속한 구간으로만 축소하여 재귀 호출
        if (target_idx <= right) {
            quick_select(start_idx, right, list, target_idx);
        }
        else {
            quick_select(right + 1, end_idx, list, target_idx);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int target_idx = nums.size() - k;
        quick_select(0, nums.size() - 1, nums, target_idx);

        return nums[target_idx];
    }
};