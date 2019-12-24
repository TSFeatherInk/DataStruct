#include<stdio.h>
#include"Usual.h"
#include"SqList.h"

Status GroupSort(Sqlist* L, int dk) {//�� �򶨼�� �� ÿ�����ݽ�������
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

Status ShellSort(Sqlist* L, int t) {//�� ��������� dk ������������ ���ϣ������
	int* dl = (int*)malloc(sizeof(int)*t);
	for (int i = 0; i < t; i++) {
		printf("�����%d��dkֵ:", i + 1);
		scanf("%d", &dl[i]);
	}
	for (int i = 0; i < t; i++) {
		GroupSort(L, dl[i]);
	}
	return 1;
}