#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
vector<int> postorderTraversal(TreeNode* root)
{

if(root != nullptr)
{
postorderTraversal(root->left);
postorderTraversal(root->right);
ret.push_back(root->val);
}
return ret;
}
};*/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;//存放后序遍历
		stack<TreeNode *> stk;
		if (root == nullptr)//空树
		{
			return ret;
		}
		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			stk.pop();//获取当前栈顶并出栈。

			if (cur != nullptr)//判断是否是标记位
			{
				stk.push(cur);//不是标记为肯定是实值，入栈，并且在其后再入栈一个标记位
				stk.push(nullptr);
				if (cur->right) stk.push(cur->right);//先入右，再入左，出栈顺序就为先左后右
				if (cur->left) stk.push(cur->left);
			}
			else//当前为标记位，则此节点（子树根）已经对其操作过
			{
				cur = stk.top(); stk.pop();//出栈入vector
				ret.push_back(cur->val);
			}
		}
		return ret;
	}
};