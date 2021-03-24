#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
void _tree2str(struct TreeNode* t, char* str)
{
	if (t == NULL)
	{
		return;
	}
	char buf[10] = { 0 };
	sprintf(buf, "%d", t->val);
	strcat(str, buf);

	if (t->left == NULL)
	{
		if (t->right == NULL)
		{
			return;
		}
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}
	if (t->right == NULL)
		return;
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}
}

char* tree2str(struct TreeNode* t)
{
	int n = 100000;
	char* str = (char*)malloc(sizeof(char)*n);
	str[0] = '\0';
	return str;
}