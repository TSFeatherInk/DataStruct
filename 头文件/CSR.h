#include <stdio.h>
#include "../头文件/Usual.h"

#define MAXSIZE 100

typedef struct
{
    int row;
    int col;
    ElemType data;
} TupNode;

typedef struct
{
    int col;
    int mark;
    ElemType data;
} CSRNode;

typedef struct
{
    int nrow;
    int ncol;
    int ndata;
    TupNode data[MAXSIZE];
} TSMatrix;

//TupNode
//data row col

//ndata nrow ncol
// data  row  col

int row, col, num;
Status **CreateMatrix()
{
    //freopen("资源文件/Matrix.txt", "r", stdin);
    num = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    ElemType **Matrix = (ElemType **)malloc(sizeof(ElemType *) * row);
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = (ElemType *)malloc(sizeof(ElemType) * col);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &Matrix[i][j]);
            if (Matrix[i][j])
            {
                num++;
            }
        }
    }
    //freopen("CON", "r", stdin);
    return Matrix;
}

TupNode *Turn_TupMatrix(ElemType **Matrix)
{
    TupNode *TupleMatrix = (TupNode *)malloc(sizeof(TupNode) * (num + 1));
    int k = 0;
    TupleMatrix[0].data = num;
    TupleMatrix[0].row = row;
    TupleMatrix[0].col = col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Matrix[i][j])
            {
                k++;
                TupleMatrix[k].data = Matrix[i][j];
                TupleMatrix[k].row = i + 1;
                TupleMatrix[k].col = j + 1;
            }
        }
    }
    return TupleMatrix;
}

CSRNode *Turn_CSR(ElemType **Matrix)
{
    CSRNode *CSRMatrix = (CSRNode *)malloc(sizeof(CSRNode) * (num + 1));
    int k = 0, flag = 0, flagk = 0;
    CSRMatrix[0].data = num;
    CSRMatrix[0].col = col;
    CSRMatrix[0].mark = row;
    for (int i = 0; i < row; i++)
    {
        flag = 1;
        flagk++;
        for (int j = 0; j < col; j++)
        {
            if (Matrix[i][j])
            {
                k++;
                CSRMatrix[k].data = Matrix[i][j];
                CSRMatrix[k].col = j + 1;
                if (flag)
                {
                    CSRMatrix[flagk].mark = k;
                    flag = 0;
                }
            }
            else if (flag)
            {
                CSRMatrix[flagk].mark = k + 1;
                flag = 0;
            }
        }
    }
    return CSRMatrix;
}

Status GetPosElem_CSR(CSRNode *CSRMatrix, int x, int y)
{
    if (x < CSRMatrix[0].mark)
    {
        for (int i = 0; i < CSRMatrix[x + 1].mark - CSRMatrix[x].mark; i++)
        {
            if (CSRMatrix[CSRMatrix[x].mark + i].col == y)
            {
                return CSRMatrix[CSRMatrix[x].mark + i].data;
            }
        }
    }
    else if (x == CSRMatrix[0].mark)
    {
        for (int i = 0; i < CSRMatrix[0].data - CSRMatrix[x].mark; i++)
        {
            if (CSRMatrix[CSRMatrix[x].mark + i].col == y)
            {
                return CSRMatrix[CSRMatrix[x].mark + i].data;
            }
        }
    }
    return 0;
}

Status** CSR_Multi(CSRNode *A, CSRNode *B)
{
    int n = 0;
    int r = A[0].mark;
    int c = B[0].col;
    // ElemType C[r][c];
    ElemType **C = (ElemType **)malloc(sizeof(ElemType *) * r);
    for (int i = 0; i < r; i++)
    {
        C[i] = (ElemType *)malloc(sizeof(ElemType) * c);
    }
    ElemType NUM;
    for(int i=1;i<=A[0].mark;i++){
        for(int j=1;j<=B[0].col;j++){
            NUM = 0;
            for(int k=1;k<=A[0].col;k++){
                // a[i][k] X b[k][j]
                //printf("a[%d][%d] * b[%d][%d] == %d\n",i,k,k,j,GetPosElem_CSR(A,i,k)*GetPosElem_CSR(B,k,j));
                NUM += GetPosElem_CSR(A,i,k)*GetPosElem_CSR(B,k,j);
            }
            //printf("NUM = %d\n",NUM);
            C[i-1][j-1] = NUM;
            if(NUM != 0){
                n++;
            }
            //printf("c[%d][%d] == %d\n",i,j,NUM);
        }
    }
    num = n;
    row = r;
    col = c;
    return C;
}

Status PrintMatrix(ElemType **Matrix)
{
    if(col == 1){
        printf("向量表示如下:\n");
    }else{
        printf("矩阵表示如下:\n");
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d ", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}

Status PrintTupleMatrix(TupNode *TupleMatrix)
{
    printf("三元组表示如下:\n");
    char d[5] = "data";
    char r[5] = "row";
    char c[5] = "col";
    printf("%4s %4s %4s\n", d, r, c);
    for (int i = 1; i <= TupleMatrix[0].data; i++)
    {
        printf("%4d %4d %4d\n", TupleMatrix[i].data, TupleMatrix[i].row, TupleMatrix[i].col);
    }
    printf("\n");
    return 1;
}

Status PrintCSRMatrix(CSRNode *CSRMatrix)
{
    printf("CSR表示如下:\n");
    char d[5] = "data";
    char r[5] = "col";
    char m[5] = "mark";
    printf("%4s %4s %4s\n", d, r, m);

    if (CSRMatrix[0].data >= CSRMatrix[0].mark)
    {
        for (int i = 1; i <= CSRMatrix[0].data; i++)
        {
            printf("%4d %4d ", CSRMatrix[i].data, CSRMatrix[i].col);
            if (i <= CSRMatrix[0].mark)
            {
                printf("%4d\n", CSRMatrix[i].mark);
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 1; i <= CSRMatrix[0].mark; i++)
        {

            if (i <= CSRMatrix[0].data)
            {
                printf("%4d %4d %4d\n", CSRMatrix[i].data, CSRMatrix[i].col, CSRMatrix[i].mark);
            }
            else
            {
                printf("          %4d\n", CSRMatrix[i].mark);
            }
        }
    }
    printf("\n");
    return 1;
}