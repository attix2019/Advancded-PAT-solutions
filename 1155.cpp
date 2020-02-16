#include<iostream>
#include<vector>

using namespace std;

int a[1005];

int n;
 
int left(int parent){
	if(parent*2 <=n)
		return parent*2;
	else return -1;
}

int right(int parent){
	if(parent*2+1 <=n)
		return parent*2+1;
	else return -1;
}

vector<int> path;
vector<vector<int> > ans;
void dfs(int root){
	if(root==-1) return;
	path.push_back(a[root]);
	if(left(root)==-1 && right(root)==-1){
//		for(int i = 0;i<path.size();i++){
//			cout<<path[i]<<" ";
//		}
//		cout<<endl;
		ans.push_back(path);
//		path.clear();
	}
	dfs(right(root));
	dfs(left(root));
	path.pop_back();
	
}
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]; 
	}
	dfs(1);
	for(int i =0;i<ans.size();i++){
		for(int j =0;j<ans[i].size()-1;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<ans[i][ans[i].size()-1]<<endl;
	}
	bool ismax=true;
	bool ismin = true;
	for(int i = 1;i<=n;i++){
		if(ismax==false&&ismin==false) break;
		if(left(i)!=-1){
			if(a[i]<a[left(i)]){
				ismax = false;
			}else{
				ismin = false;
			}	
		}
		if(right(i)!=-1){
			if(a[i]<a[right(i)]){
				ismax = false;
			}else{
				ismin = false;
			}		
		}
	}
	if(ismax) cout<<"Max Heap"<<endl;
	if(ismin) cout<<"Min Heap"<<endl;
	if(!ismax && !ismin) cout<<"Not Heap"<<endl;	
	return 0;	
}
