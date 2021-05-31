#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
/*
class Solution {
public:
vector<int> ret;
vector<int> inorderTraversal(TreeNode* root)
{
if(root != nullptr)
{
inorderTraversal(root->left);
ret.push_back(root->val);
inorderTraversal(root->right);
}
return ret;

}
};*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		stack<TreeNode *> stk;
		if (root == nullptr)//¿ÕÊ÷
		{
			return ret;
		}
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode *cur = stk.top();
			stk.pop();
			if (cur != nullptr)
			{
				if (cur->right) stk.push(cur->right);
				stk.push(cur);
				stk.push(nullptr);
				if (cur->left) stk.push(cur->left);
			}
			else
			{
				cur = stk.top();
				stk.pop();
				ret.push_back(cur->val);
			}
		}
		return ret;
	}
};
