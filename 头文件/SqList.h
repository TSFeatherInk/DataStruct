#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 50

typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType * elem;
	int length;
	int size;
}Sqlist;

Status InitSqlist(Sqlist *L){
	L->elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->length = 0;
	L->size = MAXSIZE;
}

Status AddElem(Sqlist *L,ElemType x)
{
	if(L->length<L->size)
	{
		L->elem[L->length]=x;
		L->length++;
		return 1;
	}else return 0;
}

Status AddPosElem(Sqlist *L,int pos,ElemType x)
{
	if(pos>=1&&pos<=L->length)
	{
		if(L->length<L->size)
		{
			for(int ipos=L->length-1;ipos>=pos-1;ipos--)
			{
				L->elem[ipos+1]=L->elem[ipos];
			} 
			L->elem[pos-1] = x;
			L->length++;
			return 1;
		}
		else return 0;
	}
	else return 0;
}

Status DelElem(Sqlist *L)
{
	if(L->length>0)
	{
		L->elem[L->length]=0;
		L->length--;
		return 1;
	}else return 0;
}

Status DelPosElem(Sqlist *L,int x)
{
	if(x>0&&x<=L->length)
	{
		for(int i=x-1;i<L->length;i++)
		{
			L->elem[i]=L->elem[i+1];
		}
		L->length--;
	}
	return 0;
}

Status SqlistEmpty(Sqlist *L)
{
	if (L->length != 0) {
		return 1;
	}
	else {
		return 0;
	}
}
Status SqlistLen(Sqlist *L)
{
	return L->length;
}

Status GetElemPos(Sqlist *L,ElemType x)
{
	for(int i=0;i<L->length;i++)
	{
		if(L->elem[i]==x)
		return i+1; 
	}
}

Status *GetElemPos_mult(Sqlist *L,ElemType x)
{
	int *a = (int*)malloc(sizeof(int)*(L->length+1));
	a[0]=0;
	for(int i=0;i<L->length;i++)
	{
		if(L->elem[i]==x)
		{
			a[a[0]+1]=i+1;
			a[0]++;
		} 
	}
	return a;
}
Status *CheckElem(Sqlist *L,ElemType x)
{
	int *a = (int*)malloc(sizeof(int)*(L->length+1)); 
	int c=0;
	for(int i=0;i<L->length;i++)
	{
		if(L->elem[i]==x&&c==0)
			c=1;
		else if(L->elem[i]==x&&c==1)
			c=2;
	}
	if(c==0)
	return 0;
	else if(c==1)
	{
		a[0]=1;
		a[1]= GetElemPos(L,x);
		printf("c1a[0]=%d\n",a[0]);
		return a;
	}else if(c==2)
	{
		a= GetElemPos_mult(L,x);
		printf("c2a[0]=%d\n",a[0]);
		return a;
	}
}

Status DestorySqlist(Sqlist *L)
{
	if(L->elem)
	{
		free(L->elem);
		L->length=0;
		return 1;
	}
	else return 0;
}


Status GetPosElem(Sqlist *L,int pos)
{
	if(pos>0&&pos<L->length)
	{
		return L->elem[pos-1];
	}
}

Status PrintSqlist(Sqlist *L)
{
	if (L->length != 0)
	{
		printf("Ë³Ðò±íÈçÏÂ:\n");
		for (int i = 0; i < L->length; i++)
		{
			printf("elem[%d]=%d\n", i, L->elem[i]);
		}
		return 1;
	}
	else return 0;
}