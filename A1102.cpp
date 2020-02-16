#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int left,right;
};

node tree[20];
bool root[20];
vector<int> v1,v2;

void invert(int root){
	if(root==-1) return;
	int tmp = tree[root].left;
	tree[root].left = tree[root].right;
	tree[root].right = tmp;
	invert(tree[root].left);
	invert(tree[root].right);
}

void levelTraverse(int root){
//	if(root==-1) return;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int tmp = q.front();
		v1.push_back(tmp);
		q.pop();
		if(tree[tmp].left!=-1) q.push(tree[tmp].left);
		if(tree[tmp].right!=-1) q.push(tree[tmp].right);
	}
}

void inOrder(int root){
	if(root==-1) return;
	inOrder(tree[root].left);
	v2.push_back(root);
	inOrder(tree[root].right);
}
int main(){
	int n;
	scanf("%d",&n);
	fill(root,root+n,true);
	for(int i =0; i<n; i++){
		string a,b;
		cin>>a>>b;
		if(a=="-"){
			tree[i].left = -1;
		}else{
			int l = atoi(a.c_str());
			tree[i].left = l;
			root[l] = false;
		}
		if(b=="-"){
			tree[i].right = -1;
		}else{
			int r= atoi(b.c_str());
			tree[i].right = r;
			root[r] = false;
		}
	}
	int rt;
	for(int i =0;i<n;i++){
		if(root[i]){
			rt=i;
			break;
		}
	}
	invert(rt);
	levelTraverse(rt);
	for(int i =0;i<v1.size()-1;i++){
		cout<<v1[i]<<" ";
	}
	cout<<v1[v1.size()-1]<<endl;
	inOrder(rt);
	for(int i =0;i<v2.size()-1;i++){
		cout<<v2[i]<<" ";
	}
	cout<<v2[v2.size()-1]<<endl;
	return 0;
} 
