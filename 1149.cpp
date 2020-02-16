#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

set<int> x[100005];


int main(){
	int n,m;
	cin>>n>>m;
//	fill(x,x+100005,-1);
	for(int i =0;i<n;i++){
		int a,b;
		cin>>a>>b;
		x[a].insert(b);
		x[b].insert(a);
	}
	for(int i =0;i<m;i++){
		int k;
		cin>>k;
		int goods[1005];
		bool exist[100005];
		fill(exist,exist+100005,false);
		for(int j =0;j<k;j++){
			cin>>goods[j];
			for(set<int>::iterator it = x[goods[j]].begin();it!=x[goods[j]].end();it++){
				exist[*it] = true;
			}
		}
		bool compatible = true;
		for(int j =0; j<k ;j++){
			if(exist[goods[j]]){
				cout<<"No"<<endl;
				compatible = false;
				break;
			} 
		}
		if(compatible) cout<<"Yes"<<endl;
	}
	return 0;
} 
