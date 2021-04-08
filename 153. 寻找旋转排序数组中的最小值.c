#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����ַ�
//1���� 33�⡢ 81 �⡢ 154�� ����
//2������Ѱ����Сֵ��������������������飬������Сֵ������nums[0]��λ��
//3����������ת�������飬�ҵ��յ� nums[i] ����СֵΪ MIN(nums[0], nums[i])
//4��ʹ�ö��ַ������ҵ��յ�


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