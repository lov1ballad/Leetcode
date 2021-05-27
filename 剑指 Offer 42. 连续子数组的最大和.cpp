#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include "system.h"
#include <vector>
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		if (nums.size() == 1)
			return nums[0];
		int cursum = 0;
		int prevsum = 0x80000000;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (cursum <= 0)
				cursum = nums[i];
			else
				cursum += nums[i];
			if (cursum > prevsum)
				prevsum = cursum;
		}
		return prevsum;
	}
};