#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<int> graph[10005];
vector<int> nodes1,nodes2;
set<int> nodes;
bool vis[10005];
int maxdepth = -1;

void dfs(int node,int depth, vector<int>& nodes){
	vis[node] = true;
//	cout<<node<<" ";
	if(depth > maxdepth){
		maxdepth = depth;
		nodes.clear();
		nodes.push_back(node);
	}else if(depth == maxdepth){
		nodes.push_back(node);
	}
	for(int i = 0;i<graph[node].size();i++){
		if(!vis[graph[node][i]])
			dfs(graph[node][i],depth+1,nodes);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i =0;i<n-1;i++){
		int a,b;
		cin>>a>>b; 
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fill(vis,vis+10005,false);
	int cnt=0;
	vector<int> tmp;
	for(int i =1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0,tmp);
//			cout<<i<<endl; 
			cnt++;	
		}
	}
	if(cnt>1){
		cout<<"Error: "<<cnt<<" components"<<endl;
		return 0;
	}
	fill(vis,vis+10005,false);
	dfs(1,0,nodes1);
//	cout<<endl;
	maxdepth = -1;
	fill(vis,vis+10005,false);
	dfs(nodes1[0],0,nodes2);
//	cout<<endl;
	for(int i =0;i<nodes1.size();i++){
		nodes.insert(nodes1[i]);
	}
	for(int i =0;i<nodes2.size();i++){
		nodes.insert(nodes2[i]);
	}
	for(set<int>::iterator it = nodes.begin();it!=nodes.end();it++){
		cout<<*it<<endl; 
	}
	return 0;
} 
