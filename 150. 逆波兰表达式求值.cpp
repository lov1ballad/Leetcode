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
			// strΪ����
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				// strΪ������
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
					// ��Ŀ˵���˲����ڳ���Ϊ0�����
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};