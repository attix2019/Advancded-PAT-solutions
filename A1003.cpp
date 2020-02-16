#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int teamNumber[505];
int graph[505][505];
bool visited[505];
int carryNum[505];
int dis[505];
vector<int> pre[505]; 
int pathNum = 0;
	
void DFS(int current, int start){
	if(current == start){
		pathNum ++;
		return ;
	}
	for(int i =0;i<pre[current].size();i++){
		DFS(pre[current][i], start);
	}
}

int main(){
	memset(graph,-1,sizeof(int)*505*505);
	memset(visited,false,sizeof(bool)*505);
	memset(carryNum,0,sizeof(int)*505);
//	memset(dis,99999,sizeof(dis));
	fill(dis,dis+505,1e7);
	int ncity, nroad, start, des;
	scanf("%d%d%d%d",&ncity, &nroad, &start, &des);
	
	
	for(int i = 0;i<ncity;i++){
		scanf("%d",&teamNumber[i]);
	}
	for(int i =0;i<nroad;i++){
		int c1,c2,L;
		scanf("%d%d%d",&c1,&c2,&L);
		graph[c1][c2]=L;
		graph[c2][c1]=L;
	}
	dis[start]=0;
	carryNum[start]=teamNumber[start];
	for(int i = 0;i<ncity;i++){
		int min = 1e8;
		int s = -1;
		for(int j = 0;j<ncity;j++){
			if(!visited[j] && dis[j]<min){
				min = dis[j];
				s = j;
			}
		}
		if(s==-1) break;
		visited[s]= true;
//		cout<<s<<" "<<dis[s]<<endl;
		for(int j = 0;j<ncity;j++){
			if(graph[s][j]>=0 && dis[s] + graph[s][j] < dis[j] ){
				dis[j] = dis[s] + graph[s][j];
				carryNum[j] = carryNum[s] + teamNumber[j];
				pre[j].clear();
				pre[j].push_back(s);
			}else if(graph[s][j]>=0 && dis[s] + graph[s][j] == dis[j]){
				if(carryNum[s] + teamNumber[j] > carryNum[j])
					carryNum[j] = carryNum[s] + teamNumber[j];
				pre[j].push_back(s);
			}
		}
//		cout<<s<<" "<<dis[s]<<endl;
	}
	DFS(des,start);
	cout<<pathNum<<" " << carryNum[des]<<endl;
} 


