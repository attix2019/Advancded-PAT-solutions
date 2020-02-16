#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

vector<int> graph[505];

int cnt = 0;
bool visited[505];

void dfs(int n){
	
	cnt++;
	visited[n] = true;
	
	for(int i =0;i<graph[n].size();i++){
		if(!visited[graph[n][i]])
			dfs(graph[n][i]);
	}
}

int main(){
	int n,m;
	int oddnum = 0;
	scanf("%d%d",&n,&m);
	fill(visited,visited+505,false);
	for(int i =1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int i = 1;i<n;i++){
		cout<<graph[i].size()<<" ";
		if(graph[i].size()%2 !=0 ){
			oddnum++;
		}
	}
	cout<<graph[n].size()<<endl;
	if(graph[n].size()%2 != 0) oddnum++;
	if(cnt!=n){
		cout<<"Non-Eulerian"<<endl;
		return 0;
	}
	if(oddnum==0){
		cout<<"Eulerian"<<endl;
	}else if(oddnum==2){
		cout<<"Semi-Eulerian	"<<endl;
	}else{
		cout<<"Non-Eulerian"<<endl;
	}
	return 0;
}
