#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/add-two-numbers/
#include "system.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int len1 = 1;
		int len2 = 1;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		while (p1->next != nullptr)
		{
			len1++;
			p1 = p1->next;
		}
		while (p2->next != nullptr)
		{
			len2++;
			p2 = p2->next;
		}
		if (len1>len2)
		{
			for (int i = 0; i<len1 - len2; ++i)
			{
				p2->next = new ListNode(0);
				p2 = p2->next;
			}
		}
		else
		{
			for (int i = 0; i<len2 - len1; ++i)
			{
				p1->next = new ListNode(0);
				p1 = p1->next;
			}
		}
		p1 = l1;
		p2 = l2;
		bool count = false;
		int sum = 0;
		ListNode* p3 = new ListNode(-1);
		ListNode* q = p3;
		while (p1 && p2)
		{
			sum = count + p1->val + p2->val;
			q->next = new ListNode(sum % 10);
			count = (sum >= 10 ? true : false);
			q = q->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (count)
		{
			q->next = new ListNode(1);
			q = q->next;
		}
		return p3->next;
	}
};