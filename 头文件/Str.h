#pragma once
#include<stdio.h>
#include"Usual.h"

#define MAXLEN 255
#define CHUNKSIZE 80

//串定义
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SqStr;

typedef struct {
	char* ch;
	int length;
}HStr;

//串储存结构
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int length;
}LStr;