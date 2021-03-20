#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void Swap(int* m, int* n)
{
	int tmp = *m;
	*m = *n;
	*n = tmp;
}
int Partition(int*ar, int left, int right)
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low < high && ar[high] > key)
			high--;
		Swap(&ar[high], &ar[low]);
		while (low < high && ar[low] <= key)
			low++;
		Swap(&ar[high], &ar[low]);
	}
	return low;
}
void QuickSort(int* ar, int left, int right)
{
	if (left >= right)
		return;
	int pos = Partition(ar, left, right);
	QuickSort(ar, left, pos);
	QuickSort(ar, pos + 1, right);
}
int* sortArray(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	QuickSort(nums, 0, numsSize);
	return nums;
}