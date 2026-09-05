class Solution {
    int cache[101];

    int earn(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (cache[idx] != -1) return cache[idx];

        // 현재 집(idx)을 털고 2칸/3칸 뒤로 가는 경우 중 최댓값 저장
        return cache[idx] = nums[idx] + max(earn(nums, idx + 2), earn(nums, idx + 3));
    }

public:
    int rob(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        return max(earn(nums, 0), earn(nums, 1));
    }
};