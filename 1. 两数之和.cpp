<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
#include <vector>

//https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int i, j;
		for (i = 0; i < nums.size() - 1; ++i)
		{
			for (j = i + 1; j<nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return{ i, j };
				}
			}
		}
		return{};
	}
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include "system.h"
#include <vector>

//https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int i, j;
		for (i = 0; i < nums.size() - 1; ++i)
		{
			for (j = i + 1; j<nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return{ i, j };
				}
			}
		}
		return{};
	}
>>>>>>> 18aea77efae58762237bbc2683836660408a45be
};