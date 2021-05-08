#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
//https://leetcode-cn.com/problems/min-stack/
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack()
	{}

	void push(int val)
	{
		data_st.push(val);
		if (min_st.empty() || val <= min_st.top())
			min_st.push(val);
	}

	void pop()
	{
		int val = data_st.top();
		data_st.pop();
		if (val == min_st.top())
			min_st.pop();
	}

	int top()
	{
		return data_st.top();
	}

	int getMin()
	{
		return min_st.top();
	}
private:
	stack<int> data_st;
	stack<int> min_st;
};