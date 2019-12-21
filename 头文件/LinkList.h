#include<stdio.h>
#include"Usual.h"

//单链表
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, LinkList;

Status InitLinkList(LinkList* L) {//初始化单链表
	L->data = 0;
	L->next = NULL;
	return 1;
}

Status LinkListEmpty(LinkList* L) {//判断单链表是否为空
	if (L->next) {
		return 0;
	}
	return 1;
}

Status LenLinkList(LinkList* L) {//链表长度（顺序计数）
	int num = 0;
	LNode* N;
	N = L->next;
	while (N) {
		num++;
		N = N->next;
	}
	return num;
}

Status AddLNode(LinkList* L, ElemType x) {//添加单链表节点（头插入）
	LNode* N = (LNode*)malloc(sizeof(LNode));
	if (N) {
		N->data = x;
		N->next = L->next;
		L->next = N;
		L->data++;
		return 1;
	}
	//printf("%d ", L->next->data);
	return 0;
}

Status AddLNodeT(LinkList* L, ElemType x) {//添加单链表节点（尾插入）无尾节点
	LNode* N = (LNode*)malloc(sizeof(LNode));
	LNode* T;
	T = L->next;
	if (N) {
		N->data = x;
		N->next = NULL;
		if (LinkListEmpty(L)) {
			L->next = N;
			L->data++;
		}
		else {
			while (T->next) {
				T = T->next;
			}
			T->next = N;
			L->data++;
		}
		return 1;
	}
	//printf("%d ", L->next->data);
	return 0;
}

Status AddPosLNode(LinkList* L, int pos, ElemType x) {//添加单链表节点（位置插入）
	LNode* N;
	LNode* PN = (LNode*)malloc(sizeof(LNode));
	if (PN) {
		PN->data = x;
	}
	N = L->next;
	int p = 1;
	if (pos > LenLinkList(L)+1) {
		return 0;
	}
	else {
		while (p < pos - 1) {
			N = N->next;
			p++;
		}
		PN->next = N->next;
		N->next = PN;
		L->data++;
	}
	//printf("%d ", L->next->data);
	return 1;
}

Status DelLNode(LinkList* L) {//删除单链表节点（头删除）
	LNode* N;
	if (L->next) {
		N = L->next;
		L->next = L->next->next;
		L->data--;
		if (N) {
			free(N);
		}
		return 1;
	}
	//printf("%d ", L->next->data);
	return 0;
}

Status DelPosLNode(LinkList* L, int pos) {//删除单链表节点（位置删除）
	LNode* N;
	LNode* fN;
	N = L->next;
	int p = 1;
	if (pos > LenLinkList(L)) {
		return 0;
	}
	else if(pos ==  1){
		fN = L->next;
		L->next = L->next->next;
		L->data--;
		free(fN);
	}
	else{
		while (p < pos-1) {
			N = N->next;
			p++;
		}
		fN = N->next;
		N->next = N->next->next;
		L->data--;
		free(fN);
	}
	//printf("%d ", L->next->data);
	return 1;
}

Status DelElemLNode(LinkList* L, ElemType x) {//删除单链表节点（元素删除）
	LNode* N;
	LNode* fN;
	N = L->next;
	if (N->data == x) {
		fN = L->next;
		L->next = L->next->next;
		L->data--;
		free(fN);
	}
	N = L->next;
	while (N->next) {
		if (N->next->data == x) {
			fN = N->next;
			N->next = N->next->next;
			L->data--;
			free(fN);
		}
		else {
			N = N->next;
		}
	}
	//printf("%d ", L->next->data);
	return 1;
}

Status DesLinkList(LinkList* L) {//销毁链表，由于链表表头是实体创建，所以不能释放表头
	while (!LinkListEmpty(L)) {
		DelLNode(L);
	}
	//printf("is_empty = %d\n", LinkListEmpty(&L));
	return 1;
}

Status PrintLinkList(LinkList* L) {//输出链表内容
	LNode* LN = (LNode*)malloc(sizeof(LNode));
	LN->next = L->next;
	while (LN->next){
		LN = LN->next;
		printf("%d ", LN->data);
	}
	printf("\n");
	return 1;
}

Status GetPosLNode(LinkList* L, int pos) {//获得单链表节点（由位置获取元素）
	LNode* N;
	N = L->next;
	int p = 1;
	if (pos > LenLinkList(L)) {
		return 0;
	}
	else {
		while (p < pos) {
			N = N->next;
			p++;
		}
	}
	//printf("%d ", L->next->data);
	return N->data;
}

Status GetMaxLNode(LinkList* L) {//获得单链表最大节点
	LNode* N;
	N = L->next;
	int max;
	if (!N) {
		return 0;
	}
	else {
		max = N->data;
		while (N->next) {
			if(max < N->next->data){
				max = N->next->data;
			}
			N = N->next;
		}
	}
	//printf("%d ", L->next->data);
	return max;
}

Status BubbleSortLinkList(LinkList* L) {//冒泡单链表排序
	int k = LenLinkList(L);
	int e1,e2;
	if (k > 1) {
		for (int i = 1; i < k; i++) {
			int pos1 = 1, pos2 = 2;
			for (int j = 1; j < k; j++) {
				if ((e1 = GetPosLNode(L, pos1)) > (e2 = GetPosLNode(L, pos2))) {
					printf("e1:%d e2:%d\n", e1, e2);
					DelPosLNode(L, pos1);
					PrintLinkList(L);
					AddPosLNode(L, pos2, e1);
					PrintLinkList(L);
					printf("\n");
				}
				if (pos2 < k) {
					pos1++;
					pos2++;
				}
			}
		}
	}
	return 1;
}

//双向链表
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* tail;
}DuLNode, DuLinkList;

Status InitDuLinkList(DuLinkList* L) {
	L->data = 0;
	L->prior = NULL;
	L->tail = NULL;
	return 1;
}

Status ExistElemDuList(DuLinkList* L) {
	if (L->prior) {
		return 1;
	}
	else {
		return 0;
	}
}

Status DuListAdd(DuLinkList *L, int pos, ElemType x) {
	DuLNode* N = (DuLNode*)malloc(sizeof(DuLNode));
	if (N) {
		N->data = x;
		N->tail = L->tail;
		L->tail = N;
		L->data++;
		return 1;
	}
	//printf("%d ", L->next->data);
	return 0;
}

Status DuListInsert(DuLinkList* L, int pos, ElemType x) {
	if (!(ExistElemDuList(L))) {
		return 0;
	}
	DuLNode* N = (DuLNode*)malloc(sizeof(DuLNode));
	if (N) {
		N->data = x;
		N->prior = NULL;
		N->tail = NULL;
		L->data++;
		return 1;
	}
	DuLNode* LN = L->prior;
	for (int i = 1; i < pos; i++) {
		LN = LN->prior;
	}
	LN->prior->tail = N;
	N->prior = LN->prior;
	N->tail = LN;
	LN->prior = N;
	return 0;
}

Status DuPosListDelete(DuLinkList *L, int pos) {

}

Status DuElemListDelete(DuLinkList* L, ElemType x) {

}



//#include<stdio.h>
//#include"LinkList.h"
//
//int main()
//{
//	LinkList L;
//	InitLinkList(&L);
//	printf("is_empty = %d\n", LinkListEmpty(&L));
//	for (int i = 0; i < 10; i++)
//	{
//		AddLNode(&L, i);
//	}
//	printf("is_empty = %d\n", LinkListEmpty(&L));
//	PrintLinkList(&L);
//	DesLinkList(&L);
//	printf("is_empty = %d\n", LinkListEmpty(&L));
//	printf("len_list = %d\n", LenLinkList(&L));
//	for (int i = 0; i < 10; i++)
//	{
//		AddLNode(&L, i);
//	}
//	printf("len_list = %d\n", LenLinkList(&L));
//
//	PrintLinkList(&L);
//	DelPosLNode(&L, 3);
//	PrintLinkList(&L);
//	for (int i = 0; i < 10; i++)
//	{
//		AddLNode(&L, i);
//	}
//	PrintLinkList(&L);
//	DelElemLNode(&L, 9);
//	PrintLinkList(&L);
//
//	printf("Tail_insert:\n");
//	DesLinkList(&L);
//	printf("is_empty = %d\n", LinkListEmpty(&L));
//	printf("len_list = %d\n", LenLinkList(&L));
//	for (int i = 0; i < 4; i++)
//	{
//		AddLNodeT(&L, i);
//	}
//	PrintLinkList(&L);
//	DelElemLNode(&L, 2);
//	PrintLinkList(&L);
//	for (int i = 0; i < 5; i++)
//	{
//		AddLNode(&L, i);
//	}
//
//	printf("Elem is :%d\n", GetPosLNode(&L, 2));
//	printf("开始排序:\n");
//	PrintLinkList(&L);
//	BubbleSortLinkList(&L);
//	printf("冒泡结果:\n");
//	PrintLinkList(&L);
//	return 0;
//}