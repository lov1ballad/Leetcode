#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"
//https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
#include <string>
#include <stack>
#include <vector>
class Solution {
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];
			// str为数字
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				// str为操作符
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					// 题目说明了不存在除数为0的情况
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};