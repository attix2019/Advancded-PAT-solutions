#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 40

struct node{
	int data;
	node* left, *right;
};

int post[MAX];
int in[MAX];
vector<int> ans;

node* create(int postL,int postR, int inL, int inR){
	if(postL>postR|| inL>inR) return NULL;
	int root_data = post[postR];
	node* root = new node;
	root->data = root_data;
	int k;
	for(k = inL; k<=inR;k++){
		if(in[k]==root_data) break;
	}
	int leftLen = k-inL;
	int rightLen = inR-k;
	root->left = create(postL,postL+leftLen-1,inL,k-1);
	root->right = create(postR-rightLen,postR-1, k+1,inR);
	return root;
}

void traverse(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		int data = temp->data;
		ans.push_back(data);
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right !=NULL) q.push(temp->right);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i =0;i<n;i++){
		scanf("%d",&in[i]);
	}
	int postL=0;
	int inL= 0;
	int postR=n-1;
	int inR=n-1;
	
	node* root = create(postL,postR,inL,inR);

	traverse(root);
	
	for(int i = 0;i< ans.size()-1 ;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[ans.size()-1]<<endl;
	return 0;	
}
