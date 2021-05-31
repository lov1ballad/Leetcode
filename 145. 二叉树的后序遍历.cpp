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
		vector<int> ret;//��ź������
		stack<TreeNode *> stk;
		if (root == nullptr)//����
		{
			return ret;
		}
		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			stk.pop();//��ȡ��ǰջ������ջ��

			if (cur != nullptr)//�ж��Ƿ��Ǳ��λ
			{
				stk.push(cur);//���Ǳ��Ϊ�϶���ʵֵ����ջ���������������ջһ�����λ
				stk.push(nullptr);
				if (cur->right) stk.push(cur->right);//�����ң������󣬳�ջ˳���Ϊ�������
				if (cur->left) stk.push(cur->left);
			}
			else//��ǰΪ���λ����˽ڵ㣨���������Ѿ����������
			{
				cur = stk.top(); stk.pop();//��ջ��vector
				ret.push_back(cur->val);
			}
		}
		return ret;
	}
};