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
	//���Ƚ���һ��ͷ��㣬�������Ա���Ե�һ�����������⴦��
	struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* p = ret;
	struct TreeNode* stack[MaxSize];  //�ֶ�ģ��һ��ջ
	int top = -1;
	while (root != NULL || top != -1)
	{
		while (root != NULL)             //����ģ�壬����������ȱ������ӣ��ʽ����Ӳ���ѹ��ջ��
		{
			stack[++top] = root;
			root = root->left;
		}
		if (top != -1)
		{
			root = stack[top--];        //��ջ����ʼ���ʽ��
			p->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));  //�����½�㽫��Ϣ����
			p = p->right;
			p->val = root->val;         //һ��Ҫ��֤�ṹ�����еĸ���ָ�붼����ָ�򣬷���ᱨ��
			p->right = NULL;
			p->left = NULL;
			root = root->right;         //ת������������
		}
	}
	return ret->right;        //����ͷ����������
}