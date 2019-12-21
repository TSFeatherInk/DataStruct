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

int row, col, num = 0;
Status **CreateMatrix()
{
    freopen("资源文件/Matrix.txt", "r", stdin);
    scanf("%d", &row);
    scanf("%d", &col);

    ElemType **Matrix = (ElemType **)malloc(sizeof(ElemType *) * col);
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = (ElemType *)malloc(sizeof(ElemType) * row);
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
    freopen("CON", "r", stdin);
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
            }else if(flag){
                CSRMatrix[flagk].mark = k+1;
                flag = 0;
            }
        }
    }
    return CSRMatrix;
}



Status PrintMatrix(ElemType **Matrix)
{
    printf("矩阵表示如下:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
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
    return 1;
}