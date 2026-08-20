class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right)
    {
        vector<int> temp_vec{};
        temp_vec.reserve(right - left + 1);

        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j]) temp_vec.push_back(nums[i++]);
            else temp_vec.push_back(nums[j++]);
        }

        while (i <= mid) temp_vec.push_back(nums[i++]);
        while (j <= right) temp_vec.push_back(nums[j++]);

        for (int k = 0; k < temp_vec.size(); ++k) {
            nums[left + k] = temp_vec[k];
        }

        return;
    }

    void merge_sort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return; // 기저 조건

        int mid = left + (right - left) / 2; // 올바른 중간 지점 계산

        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge(nums, left, mid, right);

        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (!nums.empty()) {
            merge_sort(nums, 0, nums.size() - 1);
        }
        return nums;
    }
};