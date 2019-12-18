#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include"Usual.h"
#define StackSize 50

typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S){
    S->base = (ElemType*)malloc(sizeof(ElemType)*StackSize);
    S->top = S->base;
    S->stacksize = StackSize;
    return 1;
}

Status Push(SqStack *S,ElemType x){
    if(S->top - S->base == StackSize){
        return 0;
    }else {
        *S->top = x;
        S->top++;
        return 1;
    }
}

Status Pop1(SqStack *S,ElemType *x){
    if(S->top - S->base == 0){
        return 0;
    }
    *x = *(S->top-1);
    S->top--;
    return 1;
}

Status Pop2(SqStack *S){
    if(S->top - S->base == 0){
        return 0;
    }
    int x;
    x = *(S->top-1);
    S->top--;
    return x;
}

Status GetTopElem(SqStack *S){
    if(S->top - S->base == 0){
        return 0;
    }
    return *(S->top-1);
}

Status SDStack(SqStack *S,int dnum,int pnum){//SelectDelete delete protect
    SqStack Q;
    InitStack(&Q);
    for(int i=0;i<pnum;i++){
        Push(&Q,Pop2(S));
    }
    for(int i=0;i<dnum;i++){
        Pop2(S);
    }
    for(int i=0;i<pnum;i++){
        Push(S,Pop2(&Q));
    }
    return 1;
}

Status PrintSatck(SqStack *S){
    for(int i=0;i<S->top-S->base;i++){
        printf("%d ",S->base[i]);
    }
    return 1;
}

#endif // STACK_H
