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
//同步
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
//同样的操作对树2进行一遍
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
//此时node1与node2分别指向树1与树2的叶子节点
if(node1->val != node2->val) return false;
}
//到此两种情况：
//1. 两个栈都空了，并且叶子节点都相等，因此返回true
//2. 只有一颗树空了，证明另一棵树一定还有别的叶子节点, 返回false;
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