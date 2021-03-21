#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	if (preorderSize == 0)
		return NULL;
	//中序中找根的位置
	int k = 0;
	while (inorder[k] != preorder[0])
		k++;
	struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = inorder[k];

	t->left = buildTree(preorder + 1, k, inorder, k);
	t->right = buildTree(preorder + k + 1, preorderSize - k - 1, inorder + k + 1, preorderSize - k - 1);
	return t;
}