#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int a[200005];

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	scanf("%d",&m);
	for(int i =0;i<m;i++){
		scanf("%ld",&a[n+i]);
	}
	sort(a,a+m+n);
	cout<<a[(m+n)/2]<<endl;
	return 0;
}
