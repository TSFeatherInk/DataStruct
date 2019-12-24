#include<stdio.h>
#include"Usual.h"
#include"SqList.h"

Status GroupSort(Sqlist* L, int dk) {//对 框定间隔 的 每组数据进行排序
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

Status ShellSort(Sqlist* L, int t) {//对 任意输入的 dk 进行依次排序 完成希尔排序
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