#include<iostream>
#include<algorithm>

using namespace std;

int cnt[505];

int main(){
	int n,m;
	cin>>n>>m;
	fill(cnt,cnt+505,0);
//	int maxcoin = -1;
	for(int i = 0;i<n;i++){
		int a;
		cin>>a;
//		if(a>maxcoin){
//			maxcoin = a;
//		} 
		cnt[a]++;
	}
	bool solved = false;
	for(int i = 1;i<=500;i++){
		if(cnt[i]==0) continue;
		cnt[i]--;
		for(int j = i;j<=500;j++){
			if(cnt[j]==0) continue;
			if(m-i==j){
				cout<<i<<" "<<j<<endl;
				solved = true;
				break;
			}
		}
		cnt[i]++;
		if(solved) break;
	}
	if(!solved) cout<<"No Solution"<<endl;
	return 0;
} 
