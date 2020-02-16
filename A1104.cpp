#include<iostream>
#include<cstdio>

using namespace std;

#define max  100005

int main(){
	int n;
	double ans = 0;
	scanf("%d", &n);
	for(int i = 1;i<=n;i++){
		double tmp;
		scanf("%lf",&tmp);
		ans += (tmp*i*(n-i+1));
	}
	printf("%.2f", ans);
	return 0;
}

/*
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1;i<=n;i++){
		scanf("%lf", &a[i]);
	}
	helper[0] = 0;
	for(int i =1;i<=n;i++){
		helper[i] = helper[i-1] + a[i];
	}
	double ans = 0;
	for(int i =1;i<=n;i++){
		for(int j = i;j<=n;j++){
			ans+=(helper[j] - helper[i-1]);
		}
	}
	printf("%.2f", ans);
	return 0;
}
*/
