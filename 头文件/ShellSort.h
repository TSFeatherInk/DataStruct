#pragma once
#include<stdio.h>
#include"Usual.h"
#include"SqList.h"

Status GroupSort(Sqlist* L, int dk) {
	for (int i = 0; i < dk; i++) {
		for (int j = i+dk; j < L->length; j += dk) {
			if (L->elem[j-dk] > L->elem[j]) {
				int temp = L->elem[j];
				L->elem[j] = L->elem[j-dk];
				L->elem[j-dk] = temp;
			}
		}
	}
	return 1;
}

Status ShellSort(Sqlist* L, int t) {
	int* dl = (int*)malloc(sizeof(int)*t);
	for (int i = 0; i < t; i++) {
		printf("输入第%d个dk值:", i + 1);
		scanf("%d", &dl[i]);
	}
	for (int i = 0; i < t; i++) {
		GroupSort(L, dl[i]);
	}
	return 1;
}

//#include<stdio.h>
//#include"Usual.h"
//#include"ShellSort.h"
//
//int main()
//{
//	Sqlist L;
//	InitSqlist(&L);
//	printf("输入待排序的数组:\n")
//		for (int i = 0; i < 10; i++) {
//			int a;
//#pragma warning(suppress : 4996)
//			scanf("%d", &a);
//			AddElem(&L, a);
//		}
//	ShellSort(&L, 5);
//	PrintSqlist(&L);
//	return 0;
//}