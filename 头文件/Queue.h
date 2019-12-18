#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include"Usual.h"

#define MAXSIZE 100

typedef struct{
    ElemType *base;
    int front;
    int rear;
}Queue;

Status InitQueue(Queue *Q){
    Q->base = (ElemType*)malloc(sizeof (ElemType)*MAXSIZE);
	if (Q) {
		Q->front = 0;
		Q->rear = 0;
		return 1;
	}
    return 0;
}

Status AddElemSqQueue(Queue *Q,ElemType x){
    Q->base[Q->rear] = x;
    Q->rear++;
    return 1;
}

Status DelElemSqQueue(Queue *Q){
    Q->front++;
    return 1;
}

Status PrintQueue(Queue *Q){
    for(int i=Q->front;i != Q->rear;i++){
        if(i==MAXSIZE){
            i=0;
        }
        printf("%d ",Q->base[i]);
    }
    return 1;
}

Status AddElemCycQueue(Queue *Q,ElemType x){
    if(Q->rear == MAXSIZE){
        Q->rear=0;
    }
    if((Q->rear+1)%MAXSIZE==Q->front){
        return 0;
    }
    Q->base[Q->rear] = x;
    Q->rear++;
    return 1;
}

Status DelElemCycQueue(Queue *Q){
    if(Q->front!=Q->rear){
        Q->front++;
    }
    if(Q->front==MAXSIZE){
        Q->front=0;
    }
    return 1;
}

#endif // QUEUE_H
