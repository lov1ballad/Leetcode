#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
//https://leetcode-cn.com/problems/implement-queue-using-stacks/
/*

*˼·��

* 1. ���ܵײ���ʲô�ṹʵ�֣���Զ��֤�����Ƚ��ȳ���һ���߼����ݽṹ��������

* 2. ����ջst1��st2,���ֱ����ջst1������Ӳ�����

* 3. ����ʱ����st2���գ�ֱ�ӳ�ջ���ǳ��ӣ���st2��Ϊ�գ����ջst1������������ݵ���st2

* 4. ��ȡ��ͷԪ��ʱ����st2���գ���ȥջ��Ԫ�ؼ�Ϊ��ͷ����Ϊ�գ�����Ҫ��ջst1������������ݵ���st2

* 5. �ж϶����Ƿ�Ϊ�գ���Ҫ��������ջ��Ϊ��ʱ�������в�Ϊ��

*/
#include <stack>
class MyQueue
{
	stack<int> st1;
	stack<int> st2;
public:
	MyQueue() {
	}
	void push(int x)
	{
		st1.push(x);
	}
	int pop()
	{
		int retval;
		if (!st2.empty())
		{
			retval = st2.top();
			st2.pop();
			return retval;
		}
		while (!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		retval = st2.top();
		st2.pop();
		return retval;
	}
	int peek()
	{
		int retval;
		if (!st2.empty())
		{
			retval = st2.top();
			return retval;
		}
		while (!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		return st2.top();
	}
	bool empty()
	{
		return st1.empty() && st2.empty();
	}
};