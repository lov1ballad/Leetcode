#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
//ͬ��
/*class Solution {
public:
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
stack<TreeNode*> s1, s2;
s1.push(root1), s2.push(root2);
while(!s1.empty() && !s2.empty())
{
TreeNode* node1 = s1.top(); s1.pop();
TreeNode* node2 = s2.top(); s2.pop();
while(node1->left || node1->right)
{
if(node1->left)
{
if(node1->right) s1.push(node1->right);
node1 = node1->left;
}
else
node1 = node1->right;
}
//ͬ���Ĳ�������2����һ��
while(node2->left || node2->right)
{
if(node2->left)
{
if(node2->right) s2.push(node2->right);
node2 = node2->left;
}
else
node2 = node2->right;
}
//��ʱnode1��node2�ֱ�ָ����1����2��Ҷ�ӽڵ�
if(node1->val != node2->val) return false;
}
//�������������
//1. ����ջ�����ˣ�����Ҷ�ӽڵ㶼��ȣ���˷���true
//2. ֻ��һ�������ˣ�֤����һ����һ�����б��Ҷ�ӽڵ�, ����false;
return s1.empty() && s2.empty();
}
};*/
//class Solution {
//public:
//	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//		vector<int> v1, v2;
//		dfs(root1, v1);
//		dfs(root2, v2);
//		return v1 == v2;
//	}
//	void dfs(TreeNode* root, vector<int>& vec)
//	{
//		if (!root->left && !root->right)
//		{
//			vec.push_back(root->val);
//			return;
//		}
//
//		if (root->left) dfs(root->left, vec);
//		if (root->right) dfs(root->right, vec);
//	}
//};