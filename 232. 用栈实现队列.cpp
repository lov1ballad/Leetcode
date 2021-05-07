#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
//https://leetcode-cn.com/problems/implement-queue-using-stacks/
/*

*思路：

* 1. 不管底层用什么结构实现，永远保证数据先进先出的一个逻辑数据结构，即队列

* 2. 创建栈st1和st2,入队直接在栈st1进行入队操作，

* 3. 出队时，若st2不空，直接出栈即是出队，若st2已为空，则把栈st1里面的所有数据导入st2

* 4. 获取队头元素时，若st2不空，就去栈顶元素即为队头，若为空，则需要把栈st1里面的所有数据导入st2

* 5. 判断队列是否为空，需要满足两个栈都为空时整个队列才为空

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