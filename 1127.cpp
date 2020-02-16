#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int in[50];
int post[50];
vector<int> ans;

struct node{
	int data;
	int h;
	node*left, * right;
};

node* create(int inL,int inR,int postL,int postR){
	if(inL > inR || postL > postR) return NULL;
	int v = post[postR];
	int k;
	for(int i = inL;i<=inR;i++){
		if(v == in[i]){
			k = i;
			break;
		}
	}
	int leftLen = k - inL;
	int rightLen = inR - k;
	node * root = new node;
	root->data = in[k];
	root->left = create(inL,k-1,postL,postL+leftLen-1);
	root->right = create(k+1,inR, postL+leftLen ,postR-1);
	return root;
}

void postTraverse(node* root){
	if(root==NULL) return ;
	postTraverse(root->left);
	postTraverse(root->right);
	cout<<root->data<<" ";
}

int height[50]; // height[i]: the number of nodes at i depth
int maxh = -1;

void bfs(node* root){
	queue<node*> q;
	root->h = 0;
	q.push(root);
	while(!q.empty()){
		node* tmp = q.front();
		if(tmp->h > maxh) maxh = tmp->h;
		q.pop();
		ans.push_back(tmp->data);
		height[tmp->h] ++;
		if(tmp->left != NULL){
			tmp->left->h = tmp->h + 1;
			q.push(tmp->left);
		}
		if(tmp->right != NULL){
			tmp->right->h = tmp->h + 1;
			q.push(tmp->right);
		}		
	}
}

int main(){
	int n;
	cin>>n;
	fill(height,height+50,0);
	for(int i =0;i<n;i++){
		cin>>in[i]; 
	}
	for(int i =0;i<n;i++){
		cin>>post[i]; 
	}
	node* root = create(0,n-1,0,n-1);
	bfs(root);
//	postTraverse(root);
//
//	for(int i = 0;i<ans.size();i++){
//		cout<<ans[i]<<" ";
//	}
	int cnt = 0;
	bool flag = false;
	for(int i =0;i<=maxh;i++){
		if(flag){ //left to right
			for(int j = cnt;j<cnt+height[i];j++){
				cout<<ans[j];
				if(j!=ans.size()-1) cout<<" ";
			}
		}else{//right to left
			for(int j = cnt+height[i]-1;j>=cnt;j--){
				cout<<ans[j];
				if(j!=ans.size()-height[maxh]) cout<<" ";
			}			
		}
		cnt+=height[i];
		flag = !flag;
	}
	cout<<endl;
	return 0;
} 









