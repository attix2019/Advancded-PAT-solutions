#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int a[100005];
int cmax[100005],cmin[100005];
int ans[100005];
int main(){
	int n;
	scanf("%d",&n);
	vector<int> candidate;
	for(int i =0;i<n;i++){
		scanf("%d", &a[i]);
	}
	if(n==0){
		cout<<0<<endl<<endl;
		return 0;	
	}
	if(n==1){
		cout<<1<<endl<<a[0]<<endl;
		return 0;
	}
//	if(n==2){
//		if(a[1]>a[0]){
//			cout<<2<<endl<<a[0]<<" "<<a[1]<<endl;
//		}else{
//			cout<<0<<endl<<endl;
//			return 0;			
//		}
//	}
	int cnt = 0;
	cmax[0] = a[0];
	cmin[n-1] = a[n-1]; 

	for(int i = 1 ; i<n; i++){
		cmax[i] = max(cmax[i-1],a[i-1]);
	}	
	for(int i =n-2;i>=0;i--){
		cmin[i] = min(cmin[i+1],a[i+1]);
	}
	for(int i = 1;i<=n-2;i++){
		if(cmax[i]<a[i] && cmin[i]>a[i]){
			ans[cnt++] = a[i];
		}
	}
	if(cmin[0] > a[0]) {
		ans[cnt++] = a[0];
	}
	if(cmax[n-1] < a[n-1]){
		ans[cnt++] = a[n-1];
	}
	if(cnt!=0) sort(ans,ans+cnt);
	cout<<cnt<<endl;
	for(int i=0;i<cnt-1;i++){
		cout<<ans[i]<<" ";
	}
	if(cnt!=0) cout<<ans[cnt-1];
	else cout<<endl;
	return 0;	
} 


// wrong vector version 
 
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int a[100005];
int cmax[100005],cmin[100005];

int main(){
	int n;
	scanf("%d",&n);
	vector<int> candidate;
	for(int i =0;i<n;i++){
		scanf("%d", &a[i]);
	}
	if(n==0){
		cout<<0<<endl<<endl;
		return 0;	
	}
	if(n==1){
		cout<<1<<endl<<a[0]<<endl;
		return 0;
	}

	
	cmax[0] = a[0];
	cmin[n-1] = a[n-1]; 
	
	for(int i = 1 ; i<n; i++){
		cmax[i] = max(cmax[i-1],a[i-1]);
	}	
	for(int i =n-2;i>=0;i--){
		cmin[i] = min(cmin[i+1],a[i+1]);
	}
	for(int i = 1;i<=n-2;i++){
		if(cmax[i]<a[i] && cmin[i]>a[i]){
			candidate.push_back(a[i]);
		}
	}
	if(cmin[0] > a[0]) candidate.insert(candidate.begin(),a[0]);
	if(cmax[n-1] < a[n-1]) candidate.push_back(a[n-1]);

	cout<<candidate.size()<<endl;
	for(int i=0;i<candidate.size()-1;i++){
		cout<<candidate[i]<<" ";
	}
	if(!candidate.empty() cout<<candidate[candidate.size()-1];
	else cout<<endl;
	return 0;	
}


