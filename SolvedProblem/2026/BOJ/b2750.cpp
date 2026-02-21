#include "pre.h"
using arr_t = std::array<int32_t, 1000>;

auto merge(arr_t& arr, int32_t left, int32_t mid, int32_t right) -> void
{
	int i = left;
	int j = mid + 1;
	int k = 0; // insertion count of temporary array

	vector<int> temp(right - left + 1);

	// compare each left, right and insert small one
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) {   // assure stable sort
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (int t = 0; t < temp.size(); t++) {
		arr[left + t] = temp[t];
	}

}

auto merge_sort(std::array<int32_t, 1000>& arr, int32_t left, int32_t right) -> void
{
	if (left >= right) return;

	int mid = (left + right) / 2;

	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main()
{
	std::array<int32_t, 1000> arr{};
	int32_t n;
	cin >> n;

	for (int32_t i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);

	return 0;
}