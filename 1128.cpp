#include<iostream>

using namespace std;

int ans[1005];
bool helper[1005][1005];
int main(){
	int ncase;
	scanf("%d",&ncase);
	for(int i = 1;i<=ncase;i++){
		fill(helper[0],helper[0]+1005*1005,true);
		int n;
		scanf("%d",&n);
		bool legal = true;
		for(int j = 1;j<=n;j++){
			scanf("%d",&ans[j]);//(ans[j],n+1-j) on board
			if(helper[ans[j]][n+1-j]==false){
				cout<<"NO"<<endl;
				legal = false;
				break;
			}
			for(int k =1;k<=n;k++){
				helper[k][n+1-j]=false;
				helper[ans[j]][k] = false;
			}
			for(int a=ans[j],b=n+1-j; a>=1&&b>=1;a--,b--){//left up
				helper[a][b] = false;
			}
			for(int a=ans[j],b=n+1-j; a<=n&&b<=n;a++,b++){//right down
				helper[a][b] = false;
			}
			for(int a=ans[j],b=n+1-j; a>=1&&b<=n;a--,b++){//right up
				helper[a][b] = false;
			}
			for(int a=ans[j],b=n+1-j; a<=n&&b>=1;a++,b--){//left down
				helper[a][b] = false;
			}
		}
		if(legal) cout<<"YES"<<endl;
	}
	return 0;
}
