#define _CRT_SECURE_NO_WARNINGS 1
#define MAX(a,b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
	if (numsSize == 0) return 0;
	if (numsSize == 1) return nums[0];
	//分两种情况dp，a为偷第1间，b为不偷第1间
	int i, a[numsSize], b[numsSize];
	a[0] = nums[0];
	a[1] = nums[0];
	b[0] = 0;
	b[1] = nums[1];
	for (i = 2; i < numsSize; i++) {
		a[i] = MAX(a[i - 1], a[i - 2] + nums[i]);
		b[i] = MAX(b[i - 1], b[i - 2] + nums[i]);
	}
	return MAX(a[numsSize - 2], b[numsSize - 1]);
}

