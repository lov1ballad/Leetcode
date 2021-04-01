#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"
int clumsy(int N)
{
	int n = N;
	int *stk = (int *)malloc(sizeof(int)* 10001);
	int top = 0;
	stk[top++] = n--; //* 先把第一个数入栈
	int sum = 0;
	while (n > 0){
		if (n > 0){
			stk[top - 1] *= n--; // * 第一步乘， 直接乘以栈内成员，原地改变
		}
		else{
			break;
		}
		if (n > 0){
			stk[top - 1] /= n--; // * 第二步除法， 直接除以栈内成员，原地改变
		}
		else{
			break;
		}
		if (n > 0){
			stk[top++] = n--; // * 第三步加， 以正数入栈
		}
		else{
			break;
		}
		if (n > 0){
			stk[top++] = -(n--); // * 第四步减， 以负数入栈
		}
	}
	for (int i = 0; i<top; i++){
		sum += stk[i];
	}

	return sum;
}