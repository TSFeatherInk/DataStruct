/* 
假设n*n 的稀疏矩阵A采用三元组表示，设计一个程序实验如下功能:
(1) 生成两个稀疏矩阵的三元组 a和 b:
(2) 输出a 转置矩阵的三元组；
(3) 输出a+b的三元组；
(4) 输出a X b 的三元组。 
*/
#include<stdio.h> 
#define N 4
#define MaxSize  100         //矩阵中非零元素最多个数
#define false 0;
#define true 1;
typedef int bool;
typedef int ElemType;
typedef struct
{
	int r;					//行号
	int c;					//列号
	ElemType d;				//元素值
} TupNode;					//三元组定义
typedef struct 
{	
	int rows;				//行数
	int cols;				//列数
	int nums;				//非零元素个数
	TupNode data[MaxSize];
} TSMatrix;					//三元组顺序表

void CreatMat(TSMatrix *t,ElemType A[N][N])  //从一个二维稀疏矩阵创建其三元组表示
{
	int i,j;
	t->rows=N;t->cols=N;t->nums=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++) 
			if (A[i][j]!=0) 	//只存储非零元素
			{
				t->data[t->nums].r=i;t->data[t->nums].c=j;
				t->data[t->nums].d=A[i][j];t->nums++;
			}
	}
}
bool Value(TSMatrix *t,ElemType x,int i,int j)  //三元组元素赋值
{
	int k=0,k1;
	if (i>=t->rows || j>=t->cols)
		return false;				//失败时返回false
	while (k<t->nums && i>t->data[k].r) k++;					//查找行
	while (k<t->nums && i==t->data[k].r && j>t->data[k].c) k++;//查找列
	if (t->data[k].r==i && t->data[k].c==j)	//存在这样的元素
		t->data[k].d=x;
	else									//不存在这样的元素时插入一个元素
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
	return true;						//成功时返回true
}

bool Assign(TSMatrix *t,ElemType *x,int i,int j)  //将指定位置的元素值赋给变量
{
	int k=0;
	if (i>=t->rows || j>=t->cols)
		return false;			//失败时返回false
	while (k<t->nums && i>t->data[k].r) k++;					//查找行
	while (k<t->nums && i==t->data[k].r && j>t->data[k].c) k++;//查找列
	if (t->data[k].r==i && t->data[k].c==j)
		*x=t->data[k].d;
	else
		*x=0;				//在三元组中没有找到表示是零元素
	return true;			//成功时返回true
}
void DispMat(TSMatrix *t)		//输出三元组
{
	int i;
	if (t->nums<=0)			//没有非零元素时返回
		return;
	printf("\t%d\t%d\t%d\n",t->rows,t->cols,t->nums);
	printf("\t------------------\n");
	for (i=0;i<t->nums;i++)
		printf("\t%d\t%d\t%d\n",t->data[i].r,t->data[i].c,t->data[i].d);
}
void TranMat(TSMatrix *t,TSMatrix *tb)		//矩阵转置
{
	int p,q=0,v;					//q为tb->data的下标
	tb->rows=t->cols;tb->cols=t->rows;tb->nums=t->nums;
	if (t->nums!=0)					//当存在非零元素时执行转置
	{
		for (v=0;v<t->cols;v++)		//tb->data[q]中的记录以c域的次序排列
			for (p=0;p<t->nums;p++)	//p为t->data的下标
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
		return false;  // 行数或列数不等时不能进行相加运算
	c->rows = a.rows; c->cols = a.cols;  // c的行列数与a的相同
	while(i < a.nums && j < b.nums) 
	{
		if(a.data[i].r == b.data[j].r)  //a, b的行号相等时 
		{
			if(a.data[i].c < b.data[j].c)  // a元素的列号小于b元素的列号 
			{
				c->data[k].r = a.data[i].r; // 将a元素添加到c中 
				c->data[k].c = a.data[i].c;
				c->data[k].d = a.data[i].d;
				k++; i++; 
			}
			else if(a.data[i].c < b.data[j].c)  // a元素的列号大于b元素的列号
			{ 
				c->data[k].r = b.data[i].r;      // 将b元素添加到c中 
				c->data[k].c = b.data[i].c;
				c->data[k].d = b.data[i].d;	
				k++; i++;
			}
			else                                 // a元素的列号等于b元素的列号
			{
				v = a.data[i].d + b.data[j].d;
				if(v!=0)						// 只将不为零的结果添加到c中 
				{
					c->data[k].r = b.data[i].r;      
					c->data[k].c = b.data[i].c;
					c->data[k].d = v;
					k++; 
				}
				i++; j++;
			}
		}
		else if(a.data[i].r < b.data[j].r)  // a元素的行号小于b元素的行号
			{ 
				c->data[k].r = a.data[i].r;      // 将a元素添加到c中 
				c->data[k].c = a.data[i].c;
				c->data[k].d = a.data[i].d;	
				k++; i++;
			}
		else							// a元素的行号大于b元素的行号
		{
			c->data[k].r = b.data[i].r;      // 将b元素添加到c中 
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
	if (k < c->nums)   // 在三元组中找到并返回其d值 
		return(c->data[k].d);
	else              // 在三元组中未找到，为零值 
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
//	//无脑的做法就是矩阵存储向量转三元表，当然CreatMat里A[N][1]也可以！ 
//	ElemType p1[N][N] = { {1 ,0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0} };
//	TSMatrix a, b, c, p;
//	CreatMat(&a, a1);
//	CreatMat(&p, p1);
//	printf("a的三元组:\n"); DispMat(&a);
//	printf("p的三元组:\n"); DispMat(&p);
//	printf("矩阵a x 向量p:\n");
//	MatMul(a, p, &c);
//	printf("a x p的三元组:\n"); DispMat(&c);
//
//	return 0;
//}


