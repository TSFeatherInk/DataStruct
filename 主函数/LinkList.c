#include<stdio.h>
#include"../头文件/LinkList.h"

int main()
{
	LinkList L;
	InitLinkList(&L);
	printf("is_empty = %d\n", LinkListEmpty(&L));
	for (int i = 0; i < 10; i++)
	{
		AddLNode(&L, i);
	}
	printf("is_empty = %d\n", LinkListEmpty(&L));
	PrintLinkList(&L);
	DesLinkList(&L);
	printf("is_empty = %d\n", LinkListEmpty(&L));
	printf("len_list = %d\n", LenLinkList(&L));
	for (int i = 0; i < 10; i++)
	{
		AddLNode(&L, i);
	}
	printf("len_list = %d\n", LenLinkList(&L));

	PrintLinkList(&L);
	DelPosLNode(&L, 3);
	PrintLinkList(&L);
	for (int i = 0; i < 10; i++)
	{
		AddLNode(&L, i);
	}
	PrintLinkList(&L);
	DelElemLNode(&L, 9);
	PrintLinkList(&L);

	printf("Tail_insert:\n");
	DesLinkList(&L);
	printf("is_empty = %d\n", LinkListEmpty(&L));
	printf("len_list = %d\n", LenLinkList(&L));
	for (int i = 0; i < 4; i++)
	{
		AddLNodeT(&L, i);
	}
	PrintLinkList(&L);
	DelElemLNode(&L, 2);
	PrintLinkList(&L);
	for (int i = 0; i < 5; i++)
	{
		AddLNode(&L, i);
	}

	printf("Elem is :%d\n", GetPosLNode(&L, 2));
	printf("开始排序:\n");
	PrintLinkList(&L);
	BubbleSortLinkList(&L);
	printf("冒泡结果:\n");
	PrintLinkList(&L);
    system("pause");
	return 0;
}