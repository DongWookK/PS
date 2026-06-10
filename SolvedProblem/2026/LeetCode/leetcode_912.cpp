class Solution {
public:
    void quick_sort(int start_idx, int end_idx, vector<int>& list)
    {
        if (end_idx <= start_idx) return;

        int32_t random_pivot_idx = start_idx + (std::rand() % (end_idx - start_idx + 1));
        std::swap(list[start_idx], list[random_pivot_idx]);

        int key = list[start_idx];

        // 호어 분할을 위해 포인터를 구간 밖에서 시작합니다.
        int left = start_idx - 1;
        int right = end_idx + 1;

        // pivot과 같은 값을 만나도 멈춰야한다. (스왑을 해야 분할되기 때문에)
        while (true)
        {
            do { ++left; } while (list[left] < key);
            do { --right; } while (list[right] > key);

            if (left >= right) break;

            std::swap(list[left], list[right]);
        }

        quick_sort(start_idx, right, list);
        quick_sort(right + 1, end_idx, list);

        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int size = nums.size();
        quick_sort(0, nums.size() - 1, nums);

        return nums;
    }
};