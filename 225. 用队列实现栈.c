#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*

*思路：

* 1. 不管底层用什么结构实现，永远保证数据先进后出的一个逻辑数据结构，即栈

* 2. 借助队列实现栈，可以使用两个队列，也可以只是用一个队列，本解只借助一个队列即可

* 3. 入栈，即把数据进行入队，为了保证栈的特性先进后出，因此需要在push方法中对入队之前的所有元素进行一次出   队入队操作，以保证所有数据达到先进后出的顺序

* 4. 出栈，由于队列数据顺序已经调整，所以只需取队头元素即可

*/
class MyStack
{
private:
	queue<int> q;
public:
	MyStack()
	{}
	void push(int x)
	{
		// 反转队列，将新元素插到队头
		int size = q.size();
		q.push(x);
		while (size--)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	int pop()
	{
		int popEle = q.front();
		q.pop();
		return popEle;
	}
	int top()
	{
		return q.front();
	}
	bool empty()
	{
		return q.empty();
	}
};