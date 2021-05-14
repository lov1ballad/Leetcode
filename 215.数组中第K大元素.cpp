#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
#include "system.h"
#include <queue>
#include <vector>
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> pq;
		for (int i = 0; i<nums.size(); ++i)
		{
			pq.push(nums[i]);
		}
		for (int i = 0; i<k - 1; ++i)
		{
			pq.pop();
		}
		return pq.top();
	}
};