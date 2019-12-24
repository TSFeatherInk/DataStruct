#include<stdio.h>
#include"../头文件/AOE.h"

int main(){
    ALGraph *G;
    freopen("资源文件/AOE.txt","r",stdin);
    CreateAOE(&G);//创建AOE网
    freopen("CON","r",stdin);
    initStack(&T);
    TopologicalOrder(*G);
    CriticalPath(*G);
    system("pause");
    return  0;
}