#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/*typedef struct TreeNode TreeNode;

int rangeSumBST(TreeNode* root, int low, int high) {
if (!root) return 0;
if (root->val < low)  return rangeSumBST(root->right, low, high);
if (root->val > high) return rangeSumBST(root->left,  low, high);
return root->val
+ rangeSumBST(root->left,  low, high)
+ rangeSumBST(root->right, low, high);
}*/

/*  ͨ�ýⷨ, ǰ����������� */
/*void dfs(struct TreeNode* root, int low, int high, int *sum) {
if (root == NULL) {
return;
}
/* �жϷ�Χ��[low, high]֮��, �����ۺ� */
/*if (root->val >= low && root->val <= high) {
*sum += root->val;
}
dfs(root->left, low, high, sum);
dfs(root->right, low, high, sum);
return;
}

int rangeSumBST(struct TreeNode* root, int low, int high){
int sum = 0;
dfs(root, low, high, &sum);
return sum;
}*/

/* ���ö���������������, ��С�Ҵ� */
int rangeSumBST(struct TreeNode* root, int low, int high){
	if (root == NULL) {
		return 0;
	}
	/* ��3��������� */
	if (root->val >= low && root->val <= high) { /* ��root�ڵ�, ������������ */
		return root->val + rangeSumBST(root->left, low, high) +
			rangeSumBST(root->right, low, high);
	}
	else if (root->val < low) { /* ���������� */
		return rangeSumBST(root->right, low, high);
	}
	else {                      /* ���������� */
		return rangeSumBST(root->left, low, high);
	}
}

