#pragma once
#include<stdio.h>
#include"Usual.h"

#define MAXLEN 255
#define CHUNKSIZE 80

//������
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SqStr;

typedef struct {
	char* ch;
	int length;
}HStr;

//������ṹ
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int length;
}LStr;