#include<iostream>

using namespace std;

int father[10005];
int tree[10005];
int picture[10005];

void init(int n){
	for(int i =0;i<n;i++){
		father[i]=i;
	}
}

int findFater(int i){
	while(i!=father[i]){
		i=father[i];
	}
	return i;
}

void union(int a,int b){
	fa = findFather(a);
	fb = findFather(b);
	if(fa!=fb){
		father[fa] = fb;
	}
}


int main(){
	int n;
	cin>>n;
	init(n);
	fill(tree,tree+10005,0);
	set<int> s;
	for(int i =0;i<n;i++){ // n pictures
		int k; // k birds in a picture
		cin>>k;
		for(int j = 0;j<k;j++){
			int b;
			cin >> b;
			if(s.find(b)!=s.end()){
				
			}else{
				s.insert(b);		
			}
		}
	}
	
}
