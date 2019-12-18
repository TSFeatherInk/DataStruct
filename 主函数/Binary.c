#include<stdio.h>
#include"../头文件/Usual.h"
#include"../头文件/Binary.h"

int main()
{
	Sqlist L;
	InitSqlist(&L);
	for (int i = 0; i < 10; i++) {
		AddElem(&L, i);
	}
	PrintSqlist(&L);
	BS(&L, 7, 0, 9);
    system("pause");
    return 0;
}