#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define SIZE 50
#define ADD 10

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList *L){
	L->elem=(ElemType*)malloc(SIZE*sizeof(ElemType));
	L->length=0;
	L->listsize=SIZE;
	return 1;
}

Status ListNumAdd(SqList *L,int n){
	if(L->length == L->listsize + ADD){//Ôö¼ÓÄÚ´æ 
		ElemType *new_elem=(ElemType*)malloc((L->listsize+ADD)*sizeof(ElemType)); 
		memcpy(new_elem,L->elem,L->length*sizeof(ElemType));
		free(L->elem);
		L->elem=new_elem;
	}
	L->elem[L->length]=n;
	L->length++;
	return 1;
}

Status QuickSort(SqList *L,int head,int tail){
	int i = head;
	int j = tail;
	int k = L->elem[(i+j)/2];
	int change;
	while(i<=j){
		while(L->elem[i]<k){
			i++;
		}
		while(L->elem[j]>k){
			j--;
		}
		if(i<=j){
			change = L->elem[i];
			L->elem[i] = L->elem[j];
			L->elem[j] = change;
			i++;
			j--;
		}
	}
	if(head<j){
		QuickSort(L,head,j);
	}
	if(i<tail){
		QuickSort(L,i,tail);
	}
	return 0;
} 

int main()
{
	SqList L;
	InitList(&L);
//	printf("%d",InitList(&L));
	int n,a;
	printf("Input num of Num:\n");
	scanf("%d",&n);
	printf("Input Nums:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		ListNumAdd(&L,a);
	}
//	for(int i=0;i<n;i++){
//		printf("%d",L.elem[i]);
//	}
	QuickSort(&L,0,L.length-1);
	printf("PutOut Sorted Nums:\n");
	for(int i=0;i<n;i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
	system("pause");
}
