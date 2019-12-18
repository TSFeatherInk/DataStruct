#pragma once
#include<stdio.h>
#include"Usual.h"

#define M 1000
#define P 13 //小于表长的最大质数

typedef struct node {
	int key;
	int count;
}HashTable;

int m = 0;

Status SearchHashTable(HashTable ha[], int k) {
	int post = k % P;
	for (int i = 0; ha[post].key!=-1&&ha[post].key!=k; i++){
		post = (post + 1) % P;
	}
	if (ha[post].key == k) {
		return post;
	}
	else {
		return -1;
	}
}

Status DeleteHashTable(HashTable ha[], int k) {
	int post = SearchHashTable(ha, k);
	if (post != -1) {
		ha[post].key = -2;
		m--;
		return 1;
	}
	else
	{
		return 0;
	}
}

Status InsertHashTable(HashTable ha[], int k) {
	int post = k % P;
	if (ha[post].key == -1 || ha[post].key == -2) {
		ha[post].key = k;
		ha[post].count = 1;
	}
	else{
		int cnt = 1;
		do{
			post = (post + 1) % P;
			cnt++;
		} while (ha[post].key != -1 && ha[post].key != -2);
		ha[post].key = k;
		ha[post].count = cnt;
	}
	m++;
	return 1;
}

Status CreateHashTable(HashTable ha[], int A[], int n) {
	for (int i = 0; i < M; i++) {
		ha[i].key = -1;
		ha[i].count = 0;
	}
	for (int i = 0; i < n; i++) {
		InsertHashTable(ha, A[i]);
	}
	return 1;
}

Status PrintHashTable(HashTable ha[],int len) {
	printf("print numbers of hashtable:\n");
	for (int i = 0; i < len; i++) {
		printf("key=%d count=%d\n", ha[i].key, ha[i].count);
	}
	return 0;
}

//#include<stdio.h>
//#include"hash.h"
//
//int main() {
//	hashtable ht[m];
//	int a[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
//	printf("now making a hash table!\n");
//	createhashtable(ht, a, 13);
//	printf("next output 9 post:\n");
//	printf("%d \n", searchhashtable(ht, 9));
//	printhashtable(ht, 13);
//	deletehashtable(ht, 12);
//	deletehashtable(ht, 6);
//	inserthashtable(ht, 21);
//	inserthashtable(ht, 37);
//	printhashtable(ht, 13);
//	return 0;
//}