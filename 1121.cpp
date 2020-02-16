#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

int couple[100005];
int ans[100005];
int cnt=0;

int main(){
	int n;
	scanf("%d",&n);
	fill(couple,couple+n,-1);
	for(int i =0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		couple[a]=b;
		couple[b]=a;
	}
	int k;
	scanf("%d",&k);
	set<int> s; 
//	vector<int> v;
	for(int i =0;i<k;i++){
		int guest;
		scanf("%d",&guest);
		s.insert(guest);
	}
	for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
		if(couple[*it] == -1){
//			v.push_back(*it);
			ans[cnt++]= *it;
			continue;
		}
		if(s.find(couple[*it])==s.end()){
			ans[cnt++]= *it;
		}
	}
	cout<<cnt<<endl;
	for(int i =0;i<cnt-1;i++){
		printf("%05d ", ans[i]);
//		cout<<ans[i]<<" ";
	}
	if(cnt!=0) 		printf("%05d", ans[cnt-1]);
//	else cout<<endl;
	return 0;
}
