#pragma once
#include<stdio.h>
#include"SqList.h"
#include"Usual.h"

Status BS(Sqlist* L,ElemType x,int l,int r) {//二分查找
	int mid = (l + r) / 2;
	if (l == r && x != L->elem[mid]) {
		printf("不存在该位置！\n");
		return 0;
	}
	
	if (x < L->elem[mid]) {
		BS(L, x, l, mid);
	}
	else if (x == L->elem[mid]) {
		printf("The Location of %d is %d\n",x,mid+1);
		return 1;
	}
	else
	{
		BS(L, x, mid+1, r);
	}
}