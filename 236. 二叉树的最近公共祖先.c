#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool findNode(struct TreeNode* root, struct TreeNode* n)
{
	if (root == NULL)
		return false;
	if (root == n)
		return true;
	return findNode(root->left, n) || findNode(root->right, n);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if (root == NULL)
		return NULL;
	if (p == root || q == root)
		return root;
	bool pInleft, pInright, qInleft, qInright;
	if (findNode(root->left, p))
	{
		pInleft = true;
		pInright = false;
	}
	else
	{
		pInleft = false;
		pInright = true;
	}
	if (findNode(root->left, q))
	{
		qInleft = true;
		qInright = false;
	}
	else{
		qInright = true;
		qInleft = false;
	}
	if (qInleft && pInleft)
		return lowestCommonAncestor(root->left, p, q);
	if (qInright && pInright)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}