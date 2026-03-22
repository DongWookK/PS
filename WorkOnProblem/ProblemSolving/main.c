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

void pre_order_traversal(struct node* node)
{
	printf("%c", node->value_);

	if (node->left_child_ != NULL)
	{
		pre_order_traversal(node->left_child_);
	}
	if (node->right_child_ != NULL)
	{
		pre_order_traversal(node->right_child_);
	}

	return;
}

void in_order_traversal(struct node* node)
{
	if (node->left_child_ != NULL)
	{
		in_order_traversal(node->left_child_);
	}

	printf("%c", node->value_);

	if (node->right_child_ != NULL)
	{
		in_order_traversal(node->right_child_);
	}

	return;
}

void post_order_traversal(struct node* node)
{
	if (node->left_child_ != NULL)
	{
		post_order_traversal(node->left_child_);
	}


	if (node->right_child_ != NULL)
	{
		post_order_traversal(node->right_child_);
	}

	printf("%c", node->value_);

	return;
}

int main() {
	int32_t n = 0;
	struct node arr[26];

	scanf("%d", &n);
	for (int32_t i = 0; i < n; ++i)
	{
		char key, left, right;
		scanf(" %c %c %c", &key, &left, &right);

		int32_t ascii = key;
		int32_t index = ascii - 65;

		arr[index].value_ = key;
		arr[index].left_value_ = left;
		arr[index].right_value_= right;
		arr[index].left_child_= NULL;
		arr[index].right_child_ = NULL;
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

	pre_order_traversal(&arr[0]);
	printf("\n");
	in_order_traversal(&arr[0]);
	printf("\n");
	post_order_traversal(&arr[0]);
	
	return 0;
}