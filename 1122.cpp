#include<vector>
#include<iostream>

using namespace std;

int graph[203][203];
bool appeared[203];

int main(){
	fill(graph[0],graph[0]+203*203,-1);

	int n,m;
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	int k;
	cin>>k;

	for(int i =0;i<k;i++){
		int len;
		int path[203];
		cin>>len;
		for(int j =0;j<len;j++){
			cin>>path[j];
		}
		if(len!= n+1){
			cout<<"NO"<<endl;
			continue;
		}
		if(path[0]!=path[len-1]){
			cout<<"NO"<<endl;
			continue;
		}
		bool finished = false;
		fill(appeared,appeared+n,false);
		for(int j =0;j<len-1;j++){
			if(appeared[j]){
				cout<<"NO"<<endl;
				finished = true;
				break;
			}else{
				appeared[j] = true;
			}
		}
		if(finished) continue;
		for(int j=0;j<len-1;j++){
			if(graph[path[j]][path[j+1]] != 1){
//				cout<<path[j]<<"->"<<path[j+1]<<endl; 
				cout<<"NO"<<endl;
				finished = true;
				break;
			}
		}
		if(!finished) cout<<"YES"<<endl;
	}
	
	return 0;
}
