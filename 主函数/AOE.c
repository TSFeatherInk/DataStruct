#include<stdio.h>
#include"../ͷ�ļ�/AOE.h"

int main(){
    ALGraph *G;
    freopen("��Դ�ļ�/AOE.txt","r",stdin);
    CreateAOE(&G);//����AOE��
    freopen("CON","r",stdin);
    initStack(&T);
    TopologicalOrder(*G);
    CriticalPath(*G);
    system("pause");
    return  0;
}