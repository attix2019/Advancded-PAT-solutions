#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int a[100005];
map<int,bool> m;

int main(){
	int n;
	cin>>n;
	int cnt= 0;
//	fill(exist,exist+n,false);
	for(int i =0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(tmp<=0) continue;
		a[i]=tmp;
		m[tmp] = true;
		cnt++;
	} 
	if(cnt==0){
		cout<<1<<endl;
		return 0;
	}
	sort(a,a+n);
	for(int k = 1;;k++){
		if(m.find(k)==m.end()){
			cout<<k<<endl;
			break;
		}
	}
//	cout<<k<<endl;
	return 0;
}
