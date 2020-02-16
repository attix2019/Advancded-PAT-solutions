#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> tree[105]; 
int leaf[105];
int deepest = 0;

void DFS(int cur, int depth){
	if(depth>deepest) deepest = depth;
	if(tree[cur].size()==0) leaf[depth]++;
	for(int i = 0;i<tree[cur].size();i++){
		DFS(tree[cur][i],depth+1);
	}
}


int main(){
	int n,m;
	fill(leaf,leaf+105,0);
	scanf("%d%d",&n,&m);
	for(int i =0; i<m; i++){
		int id,k;
		scanf("%d%d",&id,&k);
		for(int j = 0;j<k;j++){
			int temp;
			scanf("%d",&temp);
			tree[id].push_back(temp);
		}
	}
//	DFS(1,0);
//BFS
// add a h[] to record each node's depth 
//	queue<int> q;
//	q.push(1);
//	while(!q.empty()){
//		int cur = q.front();
//		q.pop();
//		if(tree[cur].size()==0){
//			leaf[depth]++;
//		}else{
//			for(int j = 0;j<tree[cur].size();j++){
//				q.push(tree[cur][j]);
//			}
//		}
//	}
	for(int i =0;i<deepest;i++){
		cout<<leaf[i]<<" ";
	}
	cout<<leaf[deepest]<<endl;
	return 0;
}
