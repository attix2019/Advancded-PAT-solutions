#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

int graph[205][205];

int main(){
	int n,m;
	cin>>n>>m;
	fill(graph[0],graph[0]+205*205,-1);
	for(int i =0;i<m;i++){
		int c1,c2,d;
		cin>>c1>>c2>>d;
		graph[c1][c2] = graph[c2][c1]= d;
	}
	int k;
	cin>>k;
	
	int mindis = 0x7ffffff;
	int minid = -1;
	int minpriority = 0;
	for(int i=1;i<=k;i++){
		string judge;
		set<int> s;
		int path[205];
		int len;
		cin>>len;
		int dis = 0;
		int priority = 0;
		for(int j = 0;j<len;j++){
			cin>>path[j];
			s.insert(path[j]);
		} 
		bool connected = true;
		for(int j=0;j<len-1;j++){
			if(graph[path[j]][path[j+1] ]== -1) {
				connected = false;
				dis = -1;
				break;	
			}else{
				dis+=graph[path[j]][path[j+1] ];
			}
		}
		if(len -1 < n || path[0]!=path[len-1] || s.size()!=n || !connected){
			judge = "(Not a TS cycle)";
			priority = 1;
		}else if(len==n+1){
			judge = "(TS simple cycle)";
			priority = 2;
		}else if(len>n+1){
			judge = "(TS cycle)";
			priority = 2;
		}
		if(dis>0 ){
			if(priority > minpriority){
				mindis = dis;
				minpriority = priority;
				minid = i;
			}else if(priority ==minpriority){
				if(mindis > dis){
					mindis = dis;
					minpriority = priority;
					minid = i;					
				}
			}
		}
		if(dis>0)
			cout<<"Path "<<i<<": "<<dis<<" "<<judge<<endl;
		else
			cout<<"Path "<<i<<": NA "<<judge<<endl;
	}
	cout<<"Shortest Dist("<<minid<<") = "<<mindis<<endl;
	return 0;
}
