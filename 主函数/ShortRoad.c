#include<stdio.h>
#include"../头文件/ShortRoad.h"

int main () {  
    freopen("资源文件/Road.txt","r",stdin);
    int i,j;  
    
    scanf("%d%d",&n,&m);//输入数据
 
    for(i = 1 ; i <= n ; ++i){//设一开始每个点都不可达 
        for(j = 1 ; j <= n ; ++j){  
            map[i][j] = INF;  
        }  
    }  
	
    int a,b,c;//输入数据 
    for(i = 1 ; i <= m ; ++i){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b] = map[b][a] = c;  
    }
    freopen("CON","r",stdin);

    int temp = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(map[i][j] == temp)
				map[i][j] = map[j][i];
		}
	}
 
    int ans = dijkstra(1,5);  
 
    printf("%d\n",ans);

    system("pause");
    return 0;  
} 
