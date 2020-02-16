#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

string forwards[1005];


int main(){
	int n,m,s;
	map<string,bool> picked;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i<=n; i++){
		cin>>forwards[i];
	} 
	bool winner = false;
	for(int i = s;i<=n;){
		if(picked.find(forwards[i])!=picked.end()){
			i++;
		}else{
			cout<<forwards[i]<<endl;
			winner= true;
			picked[forwards[i]]=true;
			i+=m;
		}
	}
	if(!winner) cout<<"Keep going..."<<endl;
	return 0;
}
