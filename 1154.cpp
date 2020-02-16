#include<set>
#include<iostream>
#include<vector>

using namespace std;

struct edge{
	int from,to;
};

vector<edge> v;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i =0;i<m;i++){
		edge tmp;
		cin>>tmp.from>>tmp.to;
		v.push_back(tmp);
	} 
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		int color[n];
		set<int> s;
		for(int j = 0;j<n;j++){
			cin>>color[j];
			s.insert(color[j]);
		}
		bool proper = true;
		for(int j = 0;j<m;j++){
			if(color[v[j].from]==color[v[j].to]){
				cout<<"No"<<endl;
				proper = false;
				break;
			}
		}
		if(proper){
			cout<<s.size()<<"-coloring"<<endl;
		}
	} 
	return 0;
}
