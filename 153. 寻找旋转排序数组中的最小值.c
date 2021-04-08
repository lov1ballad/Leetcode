#define _CRT_SECURE_NO_WARNINGS 1
//方法一：二分法
//1，和 33题、 81 题、 154题 类似
//2，此题寻找最小值，由于是升序排序的数组，所以最小值出现在nums[0]的位置
//3，由于是旋转排序数组，找到拐点 nums[i] 则最小值为 MIN(nums[0], nums[i])
//4，使用二分法快速找到拐点


#define     MIN(a, b)       ((a) < (b) ? (a) : (b))

int findMin(int* nums, int numsSize){
	int     iLeft = 0;
	int     iMid = 0;
	int     iRight = 0;
	int     iMin = 0;

	if (NULL == nums) return -1;
	if (1 == numsSize) return nums[0];
	if (2 == numsSize) return MIN(nums[0], nums[1]);

	iMin = nums[0];
	iLeft = 1;
	iRight = numsSize - 1;
	iMid = (iLeft + iRight) / 2;

	while (iLeft < iRight){
		if (nums[iMid] < iMin)
		{
			iRight = iMid;
			iMid = (iLeft + iRight) / 2;
		}
		else
		{
			iLeft = iMid + 1;
			iMid = (iLeft + iRight) / 2;
		}
	}

	return MIN(iMin, nums[iMid]);
}