#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* t)//求树高度
{
	if (t == NULL)
		return 0;
	int left_h = maxDepth(t->left);
	int right_h = maxDepth(t->right);
	return (left_h > right_h ? left_h : right_h) + 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	int max_level = maxDepth(root);
	*returnSize = max_level;//二维数组的行
	int **levelOrder = (int**)malloc(sizeof(int*)* max_level);//申请二级指针指向一个含有三个指针的数组
	*returnColumnSizes = (int*)malloc(sizeof(int)* max_level);//每一行中列的个数
	//开始层次遍历
	struct TreeNode* q1[1000], *q2[1000];//使用队列开始层次遍历
	int q1_size = 0, q2_size = 0;
	q1[0] = root;//队列1放入根节点
	q1_size++;

	int level = 0;//从顶层开始
	while (level < max_level)//循环的次数为二维数组行的大小
	{
		levelOrder[level] = (int*)malloc(sizeof(int)* q1_size);//给每一行申请空间
		for (int i = 0; i<q1_size; ++i)
			levelOrder[level][i] = q1[i]->val;//赋值
		(*returnColumnSizes)[level] = q1_size;//第一行的列的个数为队列1的大小
		for (int i = 0; i<q1_size; ++i)
		{
			if (q1[i]->left != NULL)
				q2[q2_size++] = q1[i]->left;
			if (q1[i]->right != NULL)
				q2[q2_size++] = q1[i]->right;
		}

		memcpy(q1, q2, sizeof(struct TreeNode*) * q2_size);
		q1_size = q2_size;
		q2_size = 0;

		level++;

	}

	return levelOrder;
}