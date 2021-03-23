#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* t)//�����߶�
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
	*returnSize = max_level;//��ά�������
	int **levelOrder = (int**)malloc(sizeof(int*)* max_level);//�������ָ��ָ��һ����������ָ�������
	*returnColumnSizes = (int*)malloc(sizeof(int)* max_level);//ÿһ�����еĸ���
	//��ʼ��α���
	struct TreeNode* q1[1000], *q2[1000];//ʹ�ö��п�ʼ��α���
	int q1_size = 0, q2_size = 0;
	q1[0] = root;//����1������ڵ�
	q1_size++;

	int level = 0;//�Ӷ��㿪ʼ
	while (level < max_level)//ѭ���Ĵ���Ϊ��ά�����еĴ�С
	{
		levelOrder[level] = (int*)malloc(sizeof(int)* q1_size);//��ÿһ������ռ�
		for (int i = 0; i<q1_size; ++i)
			levelOrder[level][i] = q1[i]->val;//��ֵ
		(*returnColumnSizes)[level] = q1_size;//��һ�е��еĸ���Ϊ����1�Ĵ�С
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