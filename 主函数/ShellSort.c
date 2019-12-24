#include<stdio.h>
#include"../头文件/Usual.h"
#include"../头文件/ShellSort.h"

int main()
{
	Sqlist L;
	InitSqlist(&L);
	printf("输入待排序的数组:\n");
		for (int i = 0; i < 10; i++) {
			int a;
			scanf("%d", &a);
			AddElem(&L, a);
		}
	ShellSort(&L, 5);
	PrintSqlist(&L);
	return 0;
}