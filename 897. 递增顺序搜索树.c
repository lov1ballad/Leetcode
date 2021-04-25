#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/increasing-order-search-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


#define MaxSize 1000
struct TreeNode* increasingBST(struct TreeNode* root)
{
	//首先建立一个头结点，这样可以避免对第一个结点进行特殊处理
	struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* p = ret;
	struct TreeNode* stack[MaxSize];  //手动模拟一个栈
	int top = -1;
	while (root != NULL || top != -1)
	{
		while (root != NULL)             //遍历模板，中序遍历是先遍历左孩子，故将左孩子不断压入栈中
		{
			stack[++top] = root;
			root = root->left;
		}
		if (top != -1)
		{
			root = stack[top--];        //出栈，开始访问结点
			p->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));  //申请新结点将信息存入
			p = p->right;
			p->val = root->val;         //一定要保证结构体结点中的各个指针都有所指向，否则会报错
			p->right = NULL;
			p->left = NULL;
			root = root->right;         //转而处理右子树
		}
	}
	return ret->right;        //返回头结点的右子树
}