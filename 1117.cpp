#include<algorithm>
#include<iostream>

using namespace std;

int r[100005];

bool cmp(int a,int b){
	return a > b; 
}

int main(){
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>r[i];
	}
	sort(r,r+n,cmp);
	int i = 0;
	while(i+1 < r[i]){
//		cout<<i+1<<"day "<<r[i]<<endl; 
		i++;
	}
	cout<<i<<endl;
	return 0;
}
