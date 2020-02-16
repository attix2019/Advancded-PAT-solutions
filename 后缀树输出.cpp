#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

bool isroot[30];

struct node{
	string s;
	int l,r;
};

node vs[30];

void traverse(int root){
	if(root==-1) return;
	if(vs[root].l==-1 && vs[root].r==-1){// leaf 
		cout<<"("<< vs[root].s<<")"; 
	}else if(vs[root].l!=-1 && vs[root].r!=-1){// have l adn r
		cout<<"(";
		traverse(vs[root].l);
		traverse(vs[root].r);
		cout<<vs[root].s;
		cout<<")";
	}else{//only have right
		cout<<"(";
		cout<<vs[root].s;
		traverse(vs[root].r);
		cout<<")"; 
	}
}

int main(){
	int n;
	cin>>n;
	fill(isroot,isroot+30,true);
	for(int i = 1;i<= n;i++){
		cin>>vs[i].s>>vs[i].l>>vs[i].r;
		if(vs[i].l!=-1) isroot[vs[i].l] = false;
		if(vs[i].r!=-1) isroot[vs[i].r] = false;
	} 
	int root = -1;
	for(int i = 1;i<=n;i++){
		if(isroot[i]){
			root = i;
			break;
		}
	}
	traverse(root);
	cout<<endl;
	return 0;
}
