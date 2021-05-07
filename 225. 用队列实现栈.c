#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*

*˼·��

* 1. ���ܵײ���ʲô�ṹʵ�֣���Զ��֤�����Ƚ������һ���߼����ݽṹ����ջ

* 2. ��������ʵ��ջ������ʹ���������У�Ҳ����ֻ����һ�����У�����ֻ����һ�����м���

* 3. ��ջ���������ݽ�����ӣ�Ϊ�˱�֤ջ�������Ƚ�����������Ҫ��push�����ж����֮ǰ������Ԫ�ؽ���һ�γ�   ����Ӳ������Ա�֤�������ݴﵽ�Ƚ������˳��

* 4. ��ջ�����ڶ�������˳���Ѿ�����������ֻ��ȡ��ͷԪ�ؼ���

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
		// ��ת���У�����Ԫ�ز嵽��ͷ
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