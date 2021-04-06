#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize){
	int flag = 0, temp = 0;
	for (int i = 1; i<numsSize; i++){
		if (nums[i] == nums[i - 1])flag++; //计数
		else flag = 0;  //计数器置0
		if (flag >= 2)temp++;  //移位距离加1
		nums[i - temp] = nums[i]; //移位
	}
	return numsSize - temp;
}