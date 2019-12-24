#include<stdio.h>
#include"Usual.h"

#define MAXSIZE 101
#define INF 10001

int Heap[MAXSIZE] = {0};//锟斤拷
int value[MAXSIZE] = {0};//锟斤拷锟斤拷锟斤拷亩锟斤拷锟斤拷锟?

void swap(int x, int y) {
	int t;
	t = Heap[x];
	Heap[x] = Heap[y];
	Heap[y] = t;
	return;
}

void CreateHeap() {//读入堆
	int x;
	freopen("资源文件/Heap.txt", "r", stdin);
	printf("正在从 Heap.txt 中读取初始堆:\n");
	for (int i = 1; scanf("%d",&x) && x!=EOF && i < 101; i++) {
		Heap[i] = x;
		Heap[0]++;
	}
	freopen("CON", "r", stdin);
}

void PrintHeap() {//打印堆
	printf("堆如下:\n");
	for (int i = 1; i <= Heap[0]; i++)
	{
		printf("%d ",Heap[i]);
	}
	printf("\n");
}

void ShifHeap(int pos) {//调整堆
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

void FinishHeap() {//完成堆的创建
	for (int i = Heap[0] / 2; i >= 1; i--) {
		ShifHeap(i);
	}
	return;
}

Status DelHeapMin() {//删除 最小堆 的 堆顶
	int t;
	t = Heap[1];
	Heap[1] = Heap[Heap[0]];
	Heap[0]--;
	ShifHeap(1);
	return t;
}

void HeapSort() {//对堆排序
	value[0] = Heap[0];
	for (int i = 1; i <= value[0]; i++) {
		value[i] = DelHeapMin();
	}
	printf("\n");
	printf("堆排序:\n");
	for (int i = 1; i <= value[0]; i++) {
		printf("%d ", value[i]);
	}
}