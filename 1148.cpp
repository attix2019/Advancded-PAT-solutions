#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<pair<int,int> > ans;
char a[105];
int b[105];

bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first!=b.first) return a.first<b.first;
	else return a.second < b.second;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		int tmp;
		cin>>tmp;
		if(tmp<0){
			a[i] = '-';
		}else{
			a[i] ='+';
		}
		b[i] = abs(tmp);
	} 
	for(int j = 1;j<=n-1;j++){
		for(int k = j+1;k<=n;k++){
			vector<int> liar;
//			cout<<"----j k ="<<j<< " "<<k <<endl;
			for(int i = 1;i<=n;i++){
				if((b[i]==j || b[i]==k) && a[i]!='-'){
				//把狼说成人 
//					cout<<"1:"<<i<<endl; 
					liar.push_back(i);	
				}else if((b[i]!=j && b[i]!=k) && a[i]=='-'){
//					cout<<"2:"<<i<<endl; 
					liar.push_back(i);
				} //把人说成狼 
			}
			if(liar.size()==2){
				if((liar[0]==j && liar[1]!=k) ||
				   (liar[0]==k && liar[1]!=j) ||
					(liar[1]==j && liar[0]!=k) ||
				   (liar[1]==k && liar[0]!=j))
						ans.push_back(make_pair(j,k));
			}
		}	
	}
	if(ans.empty()){
		cout<<"No Solution"<<endl;
		return 0;
	}else{
		sort(ans.begin(),ans.end(),cmp);	
	}
	cout<<ans[0].first<<" "<<ans[0].second<<endl;
	return 0;
} 
