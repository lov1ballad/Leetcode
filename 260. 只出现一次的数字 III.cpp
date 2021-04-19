#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/single-number-iii/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for (int n : nums)
			ret ^= n;
		int pos = 1;
		while ((pos & ret) == 0)
			pos <<= 1;
		int a = 0, b = 0;
		for (int n : nums)
		{
			if (n & pos)
				a ^= n;
			else
				b ^= n;
		}
		return vector<int>{a, b};
	}
};