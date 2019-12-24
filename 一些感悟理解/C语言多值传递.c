#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int* a;
	int* b;
}Turn;

Turn* value(){
	int* a=(int*)malloc(sizeof(int)*3);
	for(int i=0;i<3;i++){
		a[i]=i;
	}
	int* b=(int*)malloc(sizeof(int)*3);
	for(int i=0;i<3;i++){
		b[i]=i+3;
	}
	Turn* c = (Turn*)malloc(sizeof(Turn));
	c->a = a;
	c->b = b;
	return c;
}

int main(){
	Turn* c = value();
	int* a = (int*)malloc(sizeof(int)*3);
	a = c->a;
	int* b = (int*)malloc(sizeof(int)*3);
	b = c->b;
	for(int i=0;i<3;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=0;i<3;i++){
		printf("%d ",b[i]);
	}
	
	return 0;
}
