#include<stdio.h>
#include"../ͷ�ļ�/maze.h"

int main()
{
	char maze[10][10] = { "\0" };
	FILE *fr;
	human h;
	human start;
	human end;
	fr = fopen("��Դ�ļ�/maze.txt", "r");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			maze[i][j] = getc(fr);
			if (maze[i][j] == '0') {
				start.x = i;
				start.y = j;
				//printf("startx=%d starty=%d\n", start.x, start.y);
				start.step = 0;
				start.ord = up;
			}
			if (maze[i][j] == '1') {
				end.x = i;
				end.y = j;
				//printf("endx=%d endy=%d\n", end.x, end.y);
			}
			getc(fr);
		}
	}
	fclose(fr);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	//�Թ���ȡ���
	SqStack HS;
	InitStack(&HS);
	h = start;
	printf("h->ord:%d\n", h.ord);
	printf("startx=%d starty=%d\n", start.x, start.y);
	printf("endx=%d endy=%d\n", end.x, end.y);

	StepMaze(&h, maze, &HS, &end);

	printf("�����\n");//z����·�� o�������
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	PrintSatck(&HS);

    system("pause");
	return 0;
}