#define _CRT_SECURE_NO_WARNINGS 1
#define RESULT 1000000007
#include"system.h"
// ���� �ȽϺ���
int cmp_up(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// �ж���С�ڵ��ڵ�ǰ���ֵ����֣����ֿ��ظ�
// ���ֲ���
int search(const int *nums, int numsSize, int target)
{
	int left, right, mid;
	int last_min_position = -1;

	if (nums == NULL || numsSize == 0) {
		return -1;
	}

	left = 0;
	right = numsSize - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] <= target) {
			left = mid + 1;
			last_min_position = left;
		}
		else {
			right = mid - 1;
		}
	}

	return (last_min_position == -1) ? 0 : last_min_position;
}

int purchasePlans(int *nums, int numsSize, int target)
{
	// �������Ͷ����൱��Ҫ�����Ϊint���ͣ��������
	long cnt = 0;

	qsort(nums, numsSize, sizeof(int), cmp_up);
	for (int i = 0; i < numsSize - 1; i++) {
		cnt += search(nums + i + 1, numsSize - i - 1, target - nums[i]);
	}

	return cnt % RESULT;
}