//#define _CRT_SECURE_NO_WARNINGS 1
//inline int partition(int* a, int l, int r) {
//	int x = a[r], i = l - 1;
//	for (int j = l; j < r; ++j) {
//		if (a[j] <= x) {
//			int t = a[++i];
//			a[i] = a[j], a[j] = t;
//		}
//	}
//	int t = a[i + 1];
//	a[i + 1] = a[r], a[r] = t;
//	return i + 1;
//}
//
//inline int randomPartition(int* a, int l, int r) {
//	int i = rand() % (r - l + 1) + l;
//	int t = a[i];
//	a[i] = a[r], a[r] = t;
//	return partition(a, l, r);
//}
//
//int quickSelect(int* a, int l, int r, int index) {
//	int q = randomPartition(a, l, r);
//	if (q == index) {
//		return a[q];
//	}
//	else {
//		return q < index ? quickSelect(a, q + 1, r, index)
//			: quickSelect(a, l, q - 1, index);
//	}
//}
//
//int findKthLargest(int* nums, int numsSize, int k) {
//	srand(time(0));
//	return quickSelect(nums, 0, numsSize - 1, numsSize - k);
//}
#include<stdio.h>

int _Partition_2(int* ar, int left, int right)//挖坑法
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low < high && ar[high] > key)
			high--;
		ar[low] = ar[high];
		while (low < high && ar[low] <= key)
			low++;
		ar[high] = ar[low];
	}
	ar[low] = key;
	return low;
}

void QuickSort(int* ar, int left, int right)
{
	if (left >= right)
		return;
	int pos = _Partition_2(ar, left, right);
	QuickSort(ar, left, pos);//左子序列
	QuickSort(ar, pos + 1, right);//右子序列
}

int findKthLargest(int* nums, int numsSize, int k)
{
	QuickSort(nums, 0, numsSize);
	return nums[numsSize - k];
}
int main()
{
	int arr[6] = { 3, 2, 1, 5, 6, 4 };
	int k = findKthLargest(arr, 6, 2);
	printf("%d", k);
	return 0;
}
