#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/add-strings/
#include "system.h"

class Solution {
public:
	string addStrings(string num1, string num2)
	{
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string res;
		int sum = 0, sign = 0;
		int i = 0, j = 0;
		while (i<num1.size() && j<num2.size())
		{
			sum = (num1[i] - '0') + (num2[j] - '0') + sign;
			if (sum >= 10)
			{
				sum -= 10;
				sign = 1;
			}
			else
				sign = 0;
			res += (sum + '0');
			i++;
			j++;
		}
		while (i<num1.size())
		{
			sum = (num1[i] - '0') + sign;
			if (sum >= 10)
			{
				sum -= 10;
				sign = 1;
			}
			else
				sign = 0;
			res += (sum + '0');
			i++;
		}
		while (j<num2.size())
		{
			sum = (num2[j] - '0') + sign;
			if (sum >= 10)
			{
				sum -= 10;
				sign = 1;
			}
			else
				sign = 0;
			res += (sum + '0');
			j++;
		}
		if (sign > 0)
			res += (sign + '0');
		reverse(res.begin(), res.end());
		return res;
	}
};