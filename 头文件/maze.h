#include<stdio.h>
#include<stdlib.h>

#define up 0
#define right 1
#define down 2
#define left 3

typedef int Status;
typedef struct {
	int x, y;
	int ord;
	int step;
}human;
typedef human ElemType;

#define StackSize 100

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S) {//��ʼ��ջ
	S->base = (ElemType*)malloc(sizeof(ElemType)*StackSize);
	S->top = S->base;
	S->stacksize = StackSize;
	return 1;
}

Status Push(SqStack *S, ElemType x) {//��ջ
	if (S->top - S->base == StackSize) {
		return 0;
	}
	else {
		*S->top = x;
		S->top++;
		return 1;
	}
}

ElemType Pop(SqStack *S) {//��ջ
	ElemType* x = (ElemType*)malloc(sizeof(ElemType));
	if (S->top - S->base == 0) {
		return *x;
	}
	*x = *(S->top - 1);
	S->top--;
	return *x;
}

Status PrintSatck(SqStack *S) {//��ӡջ
	for (int i = 0; i < S->top - S->base; i++) {
		printf("��%d��:\n", S->base[i].step);
		printf("λ��: (%d,%d)\n", S->base[i].x, S->base[i].y);
		printf("����: %d\n", S->base[i].ord);
		printf("\n");
	}
	return 1;
}

Status StepMaze(human* h, char map[][10], SqStack* HS, human* end) {//�Թ���⣨��������������̽����
	if (h->x == end->x&&h->y == end->y) {
		return 1;
	}
	if (h->ord == up) {
		if (map[h->y - 1][h->x] == ' ' || map[h->y - 1][h->x] == '1') {
			Push(HS, *h);
			h->y--;
			h->step++;
			h->ord = up;
			map[h->y][h->x] = 'z';
			StepMaze(h, map, HS, end);
		}
		else {
			h->ord = right;
		}
	}
	if (h->ord == right) {
		if (map[h->y][h->x + 1] == ' ' || map[h->y][h->x + 1] == '1') {
			Push(HS, *h);
			h->x++;
			h->step++;
			h->ord = up;
			map[h->y][h->x] = 'z';
			StepMaze(h, map, HS, end);
		}
		else {
			h->ord = down;
		}
	}
	if (h->ord == down) {
		if (map[h->y + 1][h->x] == ' ' || map[h->y + 1][h->x] == '1') {
			Push(HS, *h);
			h->y++;
			h->step++;
			h->ord = up;
			map[h->y][h->x] = 'z';
			StepMaze(h, map, HS, end);
		}
		else {
			h->ord = left;
		}
	}
	if (h->ord == left) {
		if (map[h->y][h->x - 1] == ' ' || map[h->y][h->x - 1] == '1') {
			Push(HS, *h);
			h->x--;
			h->step++;
			h->ord = up;
			map[h->y][h->x] = 'z';
			StepMaze(h, map, HS, end);
		}
		else {
			*h = Pop(HS);
			//printf("ord = %d\n", h->ord);
			map[h->y][h->x] = 'o';
			/*printf("�����\n");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					printf("%c ", map[i][j]);
				}
				printf("\n");
			}*/
			StepMaze(h, map, HS, end);
		}
	}
	return 0;
}