#include<stdio.h>
#include"../ͷ�ļ�/Usual.h"
#include"../ͷ�ļ�/ShellSort.h"

int main()
{
	Sqlist L;
	InitSqlist(&L);
	printf("��������������:\n");
		for (int i = 0; i < 10; i++) {
			int a;
			scanf("%d", &a);
			AddElem(&L, a);
		}
	ShellSort(&L, 5);
	PrintSqlist(&L);
	return 0;
}