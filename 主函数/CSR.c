#include<stdio.h>
#include<stdlib.h>
#include"../头文件/CSR.h"

int main()
{
    freopen("资源文件/Matrix.txt", "r", stdin);

    printf("A ");
    ElemType** MatA = CreateMatrix();
    PrintMatrix(MatA);
    printf("A ");
    TupNode* TupA = Turn_TupMatrix(MatA);
    PrintTupleMatrix(TupA);
    printf("A ");
    CSRNode* CSRA = Turn_CSR(MatA);
    PrintCSRMatrix(CSRA);

    printf("B ");
    ElemType** MatB = CreateMatrix();
    PrintMatrix(MatB);
    printf("B ");
    TupNode* TupB = Turn_TupMatrix(MatB);
    PrintTupleMatrix(TupB);
    printf("B ");
    CSRNode* CSRB = Turn_CSR(MatB);
    PrintCSRMatrix(CSRB);

    printf("C ");
    ElemType** MatC = CreateMatrix();
    PrintMatrix(MatC);
    printf("C ");
    TupNode* TupC = Turn_TupMatrix(MatC);
    PrintTupleMatrix(TupC);
    printf("C ");
    CSRNode* CSRC = Turn_CSR(MatC);
    PrintCSRMatrix(CSRC);

    printf("压缩矩阵相乘:A x B = D\n");
    printf("D ");
    ElemType** MatD = CSR_Multi(CSRA,CSRB);
    PrintMatrix(MatD);
    printf("D ");
    TupNode* TupD = Turn_TupMatrix(MatD);
    PrintTupleMatrix(TupD);
    printf("D ");
    CSRNode* CSRD = Turn_CSR(MatD);
    PrintCSRMatrix(CSRD);

    printf("压缩矩阵乘向量:A x C = E\n");
    printf("E ");
    ElemType** MatE = CSR_Multi(CSRA,CSRC);
    PrintMatrix(MatE);
    printf("E ");
    TupNode* TupE = Turn_TupMatrix(MatE);
    PrintTupleMatrix(TupE);
    printf("E ");
    CSRNode* CSRE = Turn_CSR(MatE);
    PrintCSRMatrix(CSRE);

    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}