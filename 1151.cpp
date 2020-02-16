#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

struct node{
	int id;
	node* left;
	node* right; 
};

int in[10005],pre[10005];

node* create(int inL,int inR, int preL, int preR){
	if(inL > inR || preL > preR) return NULL;
	int r = pre[preL];
	int k;
	for(int i = inL;i<=inR;i++){
		if(in[i] == r){
			k = i;
			break;
		}
	}
	node* root = new node;
	root->id = in[k];
	int leftLen = k -inL;
	int rightLen = inR - k;
	root->left = create(inL, inL+leftLen-1, preL+1, preL+leftLen);
	root->right = create(k+1, inR, preR-rightLen+1,preR);
	return root;
}

vector<int> v1,v2;
bool find1,find2;
void dfs(node * root, int target,bool& find,vector<int> & v){
	if(root==NULL) return ;
	if(root->id == target){
		find = true;
	}
	v.push_back(root->id);
	if(!true){
		dfs(root->left,target,find,v);
		dfs(root->right,target,find,v);
	}
}

void post(node* root){
	if(root==NULL) return;
	post(root->left);
	post(root->right);
	cout<<root->id<<" ";
}
int main(){
	int  m,n;
	cin>>m>>n;
	set<int> s;
	for(int i =1;i<=n;i++){
		cin>>in[i];
		s.insert(in[i]);
	}
	for(int i =1;i<=n;i++){
		cin>>pre[i];
	}
	node* root = create(1,n,1,n);
//	post(root);
	for(int i =0;i<m;i++){
//		cout<<i<<" "<<m<<endl;
		int a,b;
		cin>>a>>b;
		v1.clear();
		v2.clear();
		find1=find2 = false;
		if(s.find(a)==s.end() && s.find(b)==s.end()){
			cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
			continue;
		}
		if(s.find(a)==s.end()){
			cout<<"ERROR: "<<a<<" is not found."<<endl;
			continue;
		}
		if(s.find(b)==s.end()){
			cout<<"ERROR: "<<b<<" is not found."<<endl;	
			continue;
		}
		dfs(root,a,find1,v1);
		dfs(root,b,find2,v2);
		int ancestor;
		for(int j=0;j<min(v1.size(),v2.size());j++){
			if(v1[j]!=v2[j]){
				ancestor = v1[j];
				break;
			}
		}
		if(ancestor == a){
			cout<<a <<" is an ancestor of "<<b<<"."<<endl;
		}else if(ancestor ==b){
			cout<<b <<" is an ancestor of "<<a<<"."<<endl;
		}else{
			cout<<"LCA of "<<a<<" and "<<b<<" is "<<ancestor<<"."<<endl;
		}
	}
	
	return 0;
} 
