#include<iostream>

using namespace std;

bool graph[1005][1005];
bool safe[1005];
int ans;
int n,m,k;

void DFS(int start,bool* visited){
	visited[start]=true;

	for(int i = 1; i<=n ; i++){
		if(graph[start][i] && safe[i] && !visited[i]){
			DFS(i,visited);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fill(graph[0],graph[0]+1005*1005,false);
	fill(safe,safe+1005,true);
	for(int i= 0;i<m;i++){
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		graph[c1][c2]=graph[c2][c1]= true;
	}
	for(int i =0;i<k;i++){
		int c;
		scanf("%d",&c);
		ans = 0;
		bool visited[1005];
		fill(visited,visited+1005,false);
		safe[c] = false;
		for(int j = 1;j<=n;j++){
			if(!visited[j] && safe[j]){
				DFS(j,visited);
				ans++;
			}
		}
		safe[c] = true;
		cout<<ans-1<<endl;
	}
	return 0;
} 
