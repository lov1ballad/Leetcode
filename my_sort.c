#define _CRT_SECURE_NO_WARNINGS 1
//#include "system.h"
#include <stdio.h>
#include <string.h>

//内部排序算法用冒泡实现
void swap(char *buf1, char *buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		//按字节进行交换
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int compare(const void *elem1, const void *elem2)
{
	//int型排序(升序)
	return (*(int*)elem1) - (*(int*)elem2);
}


void my_qsort(void* base,
	size_t num,
	size_t width,
	int(*compare)(const void *elem1, const void *elem2))
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = 0; j < num - i - 1; ++j)
		{
			if (compare(((char*)base) + j*width, ((char*)base) + (j + 1)*width)>0)
			{
				//交换数据;
				swap(((char*)base) + j*width, ((char*)base) + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	int arr[5] = { 2, 3, 8, 1, 0 };
	my_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}