#include<stdio.h>
#include<stdlib.h>
#include"../ͷ�ļ�/CSR.h"

int main()
{
    ElemType** Mat = CreateMatrix();
    PrintMatrix(Mat);

    TupNode* Tup = Turn_TupMatrix(Mat);
    PrintTupleMatrix(Tup);

    CSRNode* CSR = Turn_CSR(Mat);
    PrintCSRMatrix(CSR);

    system("pause");
    return 0;
}