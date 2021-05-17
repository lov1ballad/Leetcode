#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include "system.h"
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size()) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;
		stk.push(root);
		int inorderIndex = 0;
		for (int i = 1; i < preorder.size(); ++i) {
			int preorderVal = preorder[i];
			TreeNode* node = stk.top();
			if (node->val != inorder[inorderIndex]) {
				node->left = new TreeNode(preorderVal);
				stk.push(node->left);
			}
			else {
				while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
					node = stk.top();
					stk.pop();
					++inorderIndex;
				}
				node->right = new TreeNode(preorderVal);
				stk.push(node->right);
			}
		}
		return root;
	}
};