#include<stdio.h>
#include"../ͷ�ļ�/BitTree.h"

int main()
{
	fr = fopen("��Դ�ļ�/Tree.txt", "r");
	BitTree* T;
	T = (BitTree*)malloc(sizeof(BitTree));
	CreateBitTree(T);
	fclose(fr);
	printf("�����Ѵ� Tree.txt ����:\n");
	Print(T);
	PrintTree(t);
	printf("\n");
	printf("�������:\n");
	PrintPre(T);
	printf("\n");
	printf("�������:\n");
	PrintOrd(T);
	printf("\n");
	printf("�������:\n");
	PrintRea(T);
	printf("\n");
    system("pause");
	return 0;
}