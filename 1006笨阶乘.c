#define _CRT_SECURE_NO_WARNINGS 1
#include"system.h"
int clumsy(int N)
{
	int n = N;
	int *stk = (int *)malloc(sizeof(int)* 10001);
	int top = 0;
	stk[top++] = n--; //* �Ȱѵ�һ������ջ
	int sum = 0;
	while (n > 0){
		if (n > 0){
			stk[top - 1] *= n--; // * ��һ���ˣ� ֱ�ӳ���ջ�ڳ�Ա��ԭ�ظı�
		}
		else{
			break;
		}
		if (n > 0){
			stk[top - 1] /= n--; // * �ڶ��������� ֱ�ӳ���ջ�ڳ�Ա��ԭ�ظı�
		}
		else{
			break;
		}
		if (n > 0){
			stk[top++] = n--; // * �������ӣ� ��������ջ
		}
		else{
			break;
		}
		if (n > 0){
			stk[top++] = -(n--); // * ���Ĳ����� �Ը�����ջ
		}
	}
	for (int i = 0; i<top; i++){
		sum += stk[i];
	}

	return sum;
}