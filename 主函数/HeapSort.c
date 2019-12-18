#include<stdio.h>
#include"../头文件/HeapSort.h"

int main()
{
	CreateHeap();
	PrintHeap();
	printf("\n");
	printf("对堆调整:\n");
	FinishHeap();
	PrintHeap();
	HeapSort();
	printf("\n");
	system("pause");
	return 0;
}