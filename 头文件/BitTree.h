#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef int Status;
typedef char ElemType;

typedef struct BitTree {
	ElemType data;
	struct BitTree *left, *right;
}BitTree;

FILE *fr;
ElemType t[100] = {'\0'};
int i = 0;

Status CreateBitTree(BitTree* T) {//创建二叉树
	ElemType e;
	e = getc(fr);
	getc(fr);
	if (e == '#') {
		T->data = '#';
		return 1;
	}
	else {
		T->data = e;
		BitTree* L;
		BitTree* R;
		L = (BitTree*)malloc(sizeof(BitTree));//初始化左子树
		R = (BitTree*)malloc(sizeof(BitTree));//初始化右子树
		T->left = L;
		T->right = R;
		CreateBitTree(T->left);
		CreateBitTree(T->right);
	}
}

Status PrintPre(BitTree* T) {//先序遍历
	if (T->data != '#') {
		printf("%c ", T->data);
		PrintPre(T->left);
		PrintPre(T->right);
		return 1;
	}
	return 0;
}

Status PrintOrd(BitTree* T) {//中序遍历
	if (T->data != '#') {
		PrintOrd(T->left);
		printf("%c ", T->data);
		PrintOrd(T->right);
		return 1;
	}
	return 0;
}

Status PrintRea(BitTree* T) {//后序遍历
	if (T->data != '#') {
		PrintRea(T->left);
		PrintRea(T->right);
		printf("%c ", T->data);
		return 1;
	}
	return 0;
}

Status Print(BitTree* T) {
	if (T->data != '#') {
		Print(T->left);
		while (t[i] != '\0') {
			i++;
		}
		t[i] = T->data;
		Print(T->right);
		return 1;
	}
	else {
		while (t[i] != '\0') {
			i++;
		}
		t[i] = T->data;
		return 0;
	}
}

Status PrintTree(ElemType t[]) {
	int k = 1;
	int num = 1;
	while (i != num-1) {
		num += pow(2, k);
		k++;
	}
	printf("floor : %d\n开始打印树:\n", k-1);
	for (int e = 1; e < k; e++) {
		for (int j = (int)(i/pow(2,e)); j <= i; j+=(int)pow(2,k-e+1)) {
			printf("%c ", t[j]);
		}
		printf("\n");
	}
}

//#include<stdio.h>
//#include"BitTree.h"

//int main()
//{
//#pragma warning(suppress : 4996)
//	fr = fopen("Tree.txt", "r");
//	BitTree* T;
//	T = (BitTree*)malloc(sizeof(BitTree));
//	CreateBitTree(T);
//	fclose(fr);
//	printf("数据已从 Tree.txt 读入:\n");
//	Print(T);
//	PrintTree(t);
//	printf("\n");
//	printf("先序遍历:\n");
//	PrintPre(T);
//	printf("\n");
//	printf("中序遍历:\n");
//	PrintOrd(T);
//	printf("\n");
//	printf("后序遍历:\n");
//	PrintRea(T);
//	printf("\n");
//	return 0;
//}
//1 \ 2 3 \ 4 5 6 7
//1
//2       3
//4   5   6   7
//8 # # # # # # #

//pre: 1 2 4 # # 5 # # 3 6 # # 7 # #
//ord: 8 4 # 2 # 5 # 1 # 6 # 3 # 7 #
//rea: 8 # 4 # # 5 2 # # 6 # # 7 3 1