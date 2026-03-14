#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct node {
	char value_;
	char left_value_;
	char right_value_;
	struct node* left_child_;
	struct node* right_child_;
};

int main() {
	int32_t n = 0;
	struct node arr[26];

	scanf("%d", &n);
	for (int32_t i = 0; i < n; ++i)
	{
		char key, left, right;
		scanf(" %c %c %c", &arr[i].value_, &arr[i].left_value_, &arr[i].right_value_);
	}

	for (int32_t i = 0; i < n; ++i)
	{
		int32_t ascii = 0;
		int32_t value_index = 0;
		if (arr[i].left_value_ != '.')
		{
			ascii = arr[i].left_value_;
			value_index = ascii - 65;
			arr[i].left_child_ = &arr[value_index];
		}

		if (arr[i].right_value_ != '.')
		{
			ascii = arr[i].right_value_;
			value_index = ascii - 65;
			arr[i].right_child_ = &arr[value_index];
		}
	}

	for (int32_t i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
	
	return 0;
}