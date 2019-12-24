#include<stdio.h>
#include"../ͷ�ļ�/ShortRoad.h"

int main () {  
    freopen("��Դ�ļ�/Road.txt","r",stdin);
    int i,j;  
    
    scanf("%d%d",&n,&m);//��������
 
    for(i = 1 ; i <= n ; ++i){//��һ��ʼÿ���㶼���ɴ� 
        for(j = 1 ; j <= n ; ++j){  
            map[i][j] = INF;  
        }  
    }  
	
    int a,b,c;//�������� 
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
