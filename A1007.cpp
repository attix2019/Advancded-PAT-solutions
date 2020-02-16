#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	int dp[10005];
	fill(dp,dp+10005,0);
	scanf("%d",&n);
	vector<int> v;
	for(int i =0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
//	dp[0]= max(0,v[0]);
	int ans = -1e7;
	int last = -1;
	int first = -1;
	for(int i =1;i<n;i++){
		dp[i] = max(dp[i-1]+v[i], v[i]);
		if(dp[i] > ans) {
			ans = dp[i];
			last = i;	
		}
	}
    if(ans < 0){
        cout<<0<<" "<<v[0]<<" "<<v[n-1]<<endl;
        return 0;
    }
	int tempans = ans;
	for(int j =last;j>=0;j--){
		tempans -= v[j];
    	first = j;
		if(tempans == 0 ){
			int k = j-1;
			while(v[k]==0){
				first = k--;
			}
			break;
		}
	}
	cout<<ans <<" "<<v[first]<<" "<<v[last]<<endl;
	return 0;
} 
