#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
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
				if (cur->left) stk.push(cur->left);
				stk.push(cur);
				stk.push(nullptr);

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