#include<stdio.h>
#include"../ͷ�ļ�/HeapSort.h"

int main()
{
	CreateHeap();
	PrintHeap();
	printf("\n");
	printf("�Զѵ���:\n");
	FinishHeap();
	PrintHeap();
	HeapSort();
	printf("\n");
	system("pause");
	return 0;
}