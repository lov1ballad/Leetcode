#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize){
	int flag = 0, temp = 0;
	for (int i = 1; i<numsSize; i++){
		if (nums[i] == nums[i - 1])flag++; //����
		else flag = 0;  //��������0
		if (flag >= 2)temp++;  //��λ�����1
		nums[i - temp] = nums[i]; //��λ
	}
	return numsSize - temp;
}