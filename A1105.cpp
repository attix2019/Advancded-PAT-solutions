#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int a[10005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i =0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a,a+N,cmp);
	int m,n;
	bool isprime = true;
	for(int i =2;i<=sqrt(N);i++){
		if(N%i==0) {
			m = max(i,N/i);
			n = min(i,N/i);
			isprime = false;	
		}
	}
	
	if(isprime){
		m = N;
		n=1;
	}
//	cout<<m<<" "<<n<<endl; 
	int board[m][n];
	int i,j;
	int cnt=0;
		
	for(int layer =1;  ;layer++){
		i = layer-1;
		j = layer-1;
	
		for(;j<=n-layer;j++){
//			cout<<"("<<i<<","<<j<<")"<<endl;
			board[i][j] = a[cnt++];
			if(cnt==N) break;
		}// j = n-layer
		if(cnt==N) break;
		j--;
		i+=1;
		
		for(; i<=m-layer;i++){
//			cout<<"("<<i<<","<<j<<")"<<endl;
			board[i][j] = a[cnt++];
			if(cnt==N) break;
		} // i =m-layer
		if(cnt==N) break;
		i--;
		j-=1;
		
		for(;j>=layer-1;j--){
//			cout<<"("<<i<<","<<j<<")"<<endl;
			board[i][j] =a[cnt++];
			if(cnt==N) break;
		}//j=layer-1
		if(cnt==N) break;
		j++;
		i--; 
		
		for(;i>layer-1;i--){
//			cout<<"("<<i<<","<<j<<")"<<endl;
			board[i][j] = a[cnt++];
			if(cnt==N) break;
		}
		if(cnt==N) break;

	}
	
	for(int k =0;k<m;k++){
		for(int h=0;h<n-1;h++){
			cout<<board[k][h]<<" ";
		}
		cout<<board[k][n-1]<<endl;
	}
	return 0;
}
