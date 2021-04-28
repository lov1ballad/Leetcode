#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/sum-of-square-numbers/
bool judgeSquareSum(int c){
	int i = 0, j = (int)sqrt(c);
	while (i <= j){
		if ((long long)i * i + (long long)j * j == c) return true;
		while ((long long)i * i + (long long)j * j > c) j--;
		while ((long long)i *i + (long long)j * j < c)  i++;
	}
	return false;
}