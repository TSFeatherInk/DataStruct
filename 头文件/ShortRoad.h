#include<stdio.h>
#include<stdlib.h>

#define SIZE 110  
#define INF 1000000;  
 
int map[SIZE][SIZE];  //邻接矩阵存储 
int len[SIZE];  	//d[i]表示源点到i这个点的距离 
int visit[SIZE];  //节点是否被访问 
int n,m;  
 
int dijkstra(int from, int to){	//从源点到目标点 
	
    int i;  
    
    for(i = 1 ; i <= n ; i ++){	//初始化 
        visit[i] = 0;	//一开始每个点都没被访问 
        len[i] = map[from][i];	//先假设源点到其他点的距离 
    }  
  
    int j;  
    for(i = 1 ; i < n ; ++i){	//对除源点的每一个点进行最短计算 
        int min = INF;  //记录最小len[i] 
        int pos;  //记录小len[i] 的点 
  
        for(j = 1 ; j <= n ; ++j){	
            if(!visit[j] && min > len[j]){  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
  
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径  
                len[j] = len[pos] + map[pos][j];	//更新j节点到源节点的最短路径	
            }  
        }  
    }  
    return len[to];
}
