class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end_1 = m - 1;
        int end_2 = n - 1;
        int end_result = m + n - 1;

        // 뒤에서부터 내림차순 대입
        while (end_1 >= 0 && end_2 >= 0) {
            if (nums1[end_1] > nums2[end_2]) {
                nums1[end_result--] = nums1[end_1--];
            }
            else {
                nums1[end_result--] = nums2[end_2--];
            }
        }

        // 나머지
        while (end_2 >= 0)
        {
            nums1[end_result--] = nums2[end_2--];
        }

        return;
    }
};