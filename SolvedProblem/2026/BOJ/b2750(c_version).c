#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

void insertion_sort(uint32_t size, int* arr)
{
	for (uint32_t i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1; // j is max number of sorted list

		// find place to insert and shift backward big nubmer elements
		while (0 <= j
			&& key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
	return;
}

int main() {
	uint32_t n = 0;
	uint32_t arr[1000] = { 0 };

	scanf("%d", &n);
	for (int32_t i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	insertion_sort(n, arr);

	for (int32_t i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}