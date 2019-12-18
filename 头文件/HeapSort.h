#include<stdio.h>
#include"Usual.h"

#define MAXSIZE 101
#define INF 10001

int Heap[MAXSIZE] = {0};//ï¿½ï¿½
int value[MAXSIZE] = {0};//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä¶ï¿½ï¿½ï¿½ï¿½ï¿?

void swap(int x, int y) {
	int t;
	t = Heap[x];
	Heap[x] = Heap[y];
	Heap[y] = t;
	return;
}

void CreateHeap() {
	int x;
	freopen("×ÊÔ´ÎÄ¼þ/Heap.txt", "r", stdin);
	printf("ÕýÔÚ´Ó Heap.txt ÖÐ¶ÁÈ¡³õÊ¼¶Ñ:\n");
	for (int i = 1; scanf("%d",&x) && x!=EOF && i < 101; i++) {
		Heap[i] = x;
		Heap[0]++;
	}
	freopen("CON", "r", stdin);
}

void PrintHeap() {
	printf("¶ÑÈçÏÂ:\n");
	for (int i = 1; i <= Heap[0]; i++)
	{
		printf("%d ",Heap[i]);
	}
	printf("\n");
}

void ShifHeap(int pos) {
	int t, mark = 0;
	while (pos * 2 <= Heap[0] && mark == 0) {
		if (Heap[pos] > Heap[pos * 2]) {
			t = pos * 2;
		}
		else {
			t = pos;
		}

		if (pos * 2 + 1 <= Heap[0]) {
			if (Heap[t] > Heap[pos * 2 + 1]) {
				t = pos * 2 + 1;
			}
		}

		if (t != pos) {
			swap(t, pos);
			pos = t;
		}
		else {
			mark = 1;
		}
	}
	return;
}

void FinishHeap() {
	for (int i = Heap[0] / 2; i >= 1; i--) {
		ShifHeap(i);
	}
	return;
}

Status DelHeapMin() {
	int t;
	t = Heap[1];
	Heap[1] = Heap[Heap[0]];
	Heap[0]--;
	ShifHeap(1);
	return t;
}

void HeapSort() {
	value[0] = Heap[0];
	for (int i = 1; i <= value[0]; i++) {
		value[i] = DelHeapMin();
	}
	printf("\n");
	printf("¶ÑÅÅÐò:\n");
	for (int i = 1; i <= value[0]; i++) {
		printf("%d ", value[i]);
	}
}

//#include<stdio.h>
//#include"HeapSort.h"
//
//int main()
//{
//	CreateHeap();
//	PrintHeap();
//	printf("\n");
//	printf("ï¿½Ô¶Ñµï¿½ï¿½ï¿½:\n");
//	FinishHeap();
//	PrintHeap();
//	HeapSort();
//	return 0;
//}