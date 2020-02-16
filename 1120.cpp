#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int a[10005];
vector<int> v;
int cnt[40];

int getSum(int n){
	int sum = 0;
	while(n!=0){
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	fill(cnt,cnt+40,0);
	for(int i = 0;i<n;i++){
		int k = getSum(a[i]);
		if(cnt[k]==0){
			cnt[k]++;
			v.push_back(k);
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int i =0;i<v.size()-1;i++){
		cout<<v[i]<<" ";
	}
	cout<<v[v.size()-1];
	return 0;
}
