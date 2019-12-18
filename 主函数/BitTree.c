#include<stdio.h>
#include"../头文件/BitTree.h"

int main()
{
	fr = fopen("资源文件/Tree.txt", "r");
	BitTree* T;
	T = (BitTree*)malloc(sizeof(BitTree));
	CreateBitTree(T);
	fclose(fr);
	printf("数据已从 Tree.txt 读入:\n");
	Print(T);
	PrintTree(t);
	printf("\n");
	printf("先序遍历:\n");
	PrintPre(T);
	printf("\n");
	printf("中序遍历:\n");
	PrintOrd(T);
	printf("\n");
	printf("后序遍历:\n");
	PrintRea(T);
	printf("\n");
    system("pause");
	return 0;
}