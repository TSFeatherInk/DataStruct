/* 
����n*n ��ϡ�����A������Ԫ���ʾ�����һ������ʵ�����¹���:
(1) ��������ϡ��������Ԫ�� a�� b:
(2) ���a ת�þ������Ԫ�飻
(3) ���a+b����Ԫ�飻
(4) ���a X b ����Ԫ�顣 
*/
#include<stdio.h> 
#define N 4
#define MaxSize  100         //�����з���Ԫ��������
#define false 0;
#define true 1;
typedef int bool;
typedef int ElemType;
typedef struct
{
	int r;					//�к�
	int c;					//�к�
	ElemType d;				//Ԫ��ֵ
} TupNode;					//��Ԫ�鶨��
typedef struct 
{	
	int rows;				//����
	int cols;				//����
	int nums;				//����Ԫ�ظ���
	TupNode data[MaxSize];
} TSMatrix;					//��Ԫ��˳���

void CreatMat(TSMatrix *t,ElemType A[N][N])  //��һ����άϡ����󴴽�����Ԫ���ʾ
{
	int i,j;
	t->rows=N;t->cols=N;t->nums=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++) 
			if (A[i][j]!=0) 	//ֻ�洢����Ԫ��
			{
				t->data[t->nums].r=i;t->data[t->nums].c=j;
				t->data[t->nums].d=A[i][j];t->nums++;
			}
	}
}
bool Value(TSMatrix *t,ElemType x,int i,int j)  //��Ԫ��Ԫ�ظ�ֵ
{
	int k=0,k1;
	if (i>=t->rows || j>=t->cols)
		return false;				//ʧ��ʱ����false
	while (k<t->nums && i>t->data[k].r) k++;					//������
	while (k<t->nums && i==t->data[k].r && j>t->data[k].c) k++;//������
	if (t->data[k].r==i && t->data[k].c==j)	//����������Ԫ��
		t->data[k].d=x;
	else									//������������Ԫ��ʱ����һ��Ԫ��
	{	
		for (k1=t->nums-1;k1>=k;k1--)
		{
			t->data[k1+1].r=t->data[k1].r;
			t->data[k1+1].c=t->data[k1].c;
			t->data[k1+1].d=t->data[k1].d;
		}
		t->data[k].r=i;t->data[k].c=j;t->data[k].d=x;
		t->nums++;
	}
	return true;						//�ɹ�ʱ����true
}

bool Assign(TSMatrix *t,ElemType *x,int i,int j)  //��ָ��λ�õ�Ԫ��ֵ��������
{
	int k=0;
	if (i>=t->rows || j>=t->cols)
		return false;			//ʧ��ʱ����false
	while (k<t->nums && i>t->data[k].r) k++;					//������
	while (k<t->nums && i==t->data[k].r && j>t->data[k].c) k++;//������
	if (t->data[k].r==i && t->data[k].c==j)
		*x=t->data[k].d;
	else
		*x=0;				//����Ԫ����û���ҵ���ʾ����Ԫ��
	return true;			//�ɹ�ʱ����true
}
void DispMat(TSMatrix *t)		//�����Ԫ��
{
	int i;
	if (t->nums<=0)			//û�з���Ԫ��ʱ����
		return;
	printf("\t%d\t%d\t%d\n",t->rows,t->cols,t->nums);
	printf("\t------------------\n");
	for (i=0;i<t->nums;i++)
		printf("\t%d\t%d\t%d\n",t->data[i].r,t->data[i].c,t->data[i].d);
}
void TranMat(TSMatrix *t,TSMatrix *tb)		//����ת��
{
	int p,q=0,v;					//qΪtb->data���±�
	tb->rows=t->cols;tb->cols=t->rows;tb->nums=t->nums;
	if (t->nums!=0)					//�����ڷ���Ԫ��ʱִ��ת��
	{
		for (v=0;v<t->cols;v++)		//tb->data[q]�еļ�¼��c��Ĵ�������
			for (p=0;p<t->nums;p++)	//pΪt->data���±�
				if (t->data[p].c==v)
				{
					tb->data[q].r=t->data[p].c;
					tb->data[q].c=t->data[p].r;
					tb->data[q].d=t->data[p].d;
					q++;
				}
	}
}

bool MatAdd(TSMatrix a, TSMatrix b, TSMatrix *c)
{
	int i = 0, j = 0, k = 0;
	ElemType v;
	if (a.rows != b.rows || a.cols != b.cols)  
		return false;  // ��������������ʱ���ܽ����������
	c->rows = a.rows; c->cols = a.cols;  // c����������a����ͬ
	while(i < a.nums && j < b.nums) 
	{
		if(a.data[i].r == b.data[j].r)  //a, b���к����ʱ 
		{
			if(a.data[i].c < b.data[j].c)  // aԪ�ص��к�С��bԪ�ص��к� 
			{
				c->data[k].r = a.data[i].r; // ��aԪ����ӵ�c�� 
				c->data[k].c = a.data[i].c;
				c->data[k].d = a.data[i].d;
				k++; i++; 
			}
			else if(a.data[i].c < b.data[j].c)  // aԪ�ص��кŴ���bԪ�ص��к�
			{ 
				c->data[k].r = b.data[i].r;      // ��bԪ����ӵ�c�� 
				c->data[k].c = b.data[i].c;
				c->data[k].d = b.data[i].d;	
				k++; i++;
			}
			else                                 // aԪ�ص��кŵ���bԪ�ص��к�
			{
				v = a.data[i].d + b.data[j].d;
				if(v!=0)						// ֻ����Ϊ��Ľ����ӵ�c�� 
				{
					c->data[k].r = b.data[i].r;      
					c->data[k].c = b.data[i].c;
					c->data[k].d = v;
					k++; 
				}
				i++; j++;
			}
		}
		else if(a.data[i].r < b.data[j].r)  // aԪ�ص��к�С��bԪ�ص��к�
			{ 
				c->data[k].r = a.data[i].r;      // ��aԪ����ӵ�c�� 
				c->data[k].c = a.data[i].c;
				c->data[k].d = a.data[i].d;	
				k++; i++;
			}
		else							// aԪ�ص��кŴ���bԪ�ص��к�
		{
			c->data[k].r = b.data[i].r;      // ��bԪ����ӵ�c�� 
			c->data[k].c = b.data[i].c;
			c->data[k].d = b.data[i].d;	
			k++; i++;
		}
		c->nums = k;
	}
	return true;	
}
int getvalue(TSMatrix *c, int i, int j)
{
	int k = 0;
	while(k < c->nums && (c->data[k].r != i || c->data[k].c != j))
		k++;
	if (k < c->nums)   // ����Ԫ�����ҵ���������dֵ 
		return(c->data[k].d);
	else              // ����Ԫ����δ�ҵ���Ϊ��ֵ 
		return(0);
}
bool MatMul(TSMatrix a, TSMatrix b, TSMatrix *c)
{
	int i, j, k, p = 0;
	ElemType s;
	if (a.cols != b.rows) 
		return false;
	for (i=0;i<a.rows;i++)
		for (j=0;j<b.cols;j++)
		{
			s = 0;
			for (k = 0; k < a.cols; k++)
				s += getvalue(&a, i, k) * getvalue(&b, k, j);
			if (s != 0)
			{
				c->data[p].r = i;
				c->data[p].c = j;
				c->data[p].d = s;
				p++;	
			}
		}
	c->rows = a.rows;
	c->cols = b.cols;
	c->nums = p;
	return true;
}

//#include<stdio.h>
//#include"CSR.h"
//
//int main()
//{
//	ElemType a1[N][N] = { {1, 0, 3, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 1} };
//	//���Ե��������Ǿ���洢����ת��Ԫ����ȻCreatMat��A[N][1]Ҳ���ԣ� 
//	ElemType p1[N][N] = { {1 ,0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0} };
//	TSMatrix a, b, c, p;
//	CreatMat(&a, a1);
//	CreatMat(&p, p1);
//	printf("a����Ԫ��:\n"); DispMat(&a);
//	printf("p����Ԫ��:\n"); DispMat(&p);
//	printf("����a x ����p:\n");
//	MatMul(a, p, &c);
//	printf("a x p����Ԫ��:\n"); DispMat(&c);
//
//	return 0;
//}


