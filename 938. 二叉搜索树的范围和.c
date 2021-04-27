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

/*  通用解法, 前序遍历二叉树 */
/*void dfs(struct TreeNode* root, int low, int high, int *sum) {
if (root == NULL) {
return;
}
/* 判断范围在[low, high]之间, 进行累和 */
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

/* 利用二叉搜索树的特性, 左小右大 */
int rangeSumBST(struct TreeNode* root, int low, int high){
	if (root == NULL) {
		return 0;
	}
	/* 分3种情况讨论 */
	if (root->val >= low && root->val <= high) { /* 加root节点, 处理左右子树 */
		return root->val + rangeSumBST(root->left, low, high) +
			rangeSumBST(root->right, low, high);
	}
	else if (root->val < low) { /* 处理右子树 */
		return rangeSumBST(root->right, low, high);
	}
	else {                      /* 处理左子树 */
		return rangeSumBST(root->left, low, high);
	}
}

