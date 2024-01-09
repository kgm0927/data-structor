#pragma once

#include <stdio.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

extern TreeNode* search(TreeNode* node, int key) {
	while (node!=NULL)
	{
		if (key < node->key) return node;
		else if (key<node->key)
		{
			node = node->left;
		}
		else
		{
			node=node-> right;
		}

	}
	return NULL;
}