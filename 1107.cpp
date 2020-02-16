#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int father[1005];
int hobby_lover[1005];
int root[1005];

void init(int n){
	for(int i =1;i<=n;i++){
		father[i] = i;
	}
}

int findFather(int n){
	while(n!=father[n]){
		n = father[n];
	}
	return n;
}

void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa!=fb) father[fa] = fb; 
}

bool cmp(int a, int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	fill(hobby_lover,hobby_lover+1005,0);
	fill(root,root+1005,0);
	init(n);
	for(int i = 1;i<=n;i++){
		string s;
		cin>>s; 
		int k = atoi(s.substr(0,s.length()-1).c_str());
		for(int j = 0;j<k;j++){
			int h;
			cin>>h;
			if(hobby_lover[h]==0){
				hobby_lover[h] = i;// i th perple have hobby h
			}
//			cout<<"for hobby:"<<h<<" union "<<hobby_lover[h]<<" "<<i<<endl;;
			Union(hobby_lover[h],i);
//			cout<<father[1]<<endl;
		} 
	} 
	int cnt = 0;
	for(int i =1;i<=n;i++){
		if(father[i] ==i) cnt++;
		root[findFather(i)]++;
//		cout<<father[i]<<" "<<endl; 
	}
	cout<<cnt<<endl;
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(root[i]!=0){
			ans.push_back(root[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i];
		if(i!=ans.size()-1) cout<<" ";
	}
	return 0;
	
}
