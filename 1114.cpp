#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int father[100005];
double cntState[100005];
double cntArea[100005];
bool exist[100005];
int number[100005];
void init(){
	for(int i = 0;i<100005;i++) father[i] = i;
}

struct record{
	int id;
	int number;
	double state,area;
};
int findFather(int n){
	while(n!=father[n]){
		n=father[n];
	}
	return n;
}

void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
//	cout<<"union"<<a<<"(father:"<<fa<<") and" <<b<<"("<<fb<<"),"<<endl;
	
	if(fa!=fb){
		if(fa>fb){
			father[fa] = fb;
			cntState[fb] += cntState[fa];
//			cnntState[fa] = cntState[fa];
			cntArea[fb] += cntArea[fa];
//			cnntState[fb] = cntState[fa];
		}else{
			father[fb] = fa;
			cntState[fa] += cntState[fb];
//			cnntState[fa] = cntState[fa];
			cntArea[fa] += cntArea[fb];
		}		
	}
	
}
//given in descending order of their average areas, 
//and in ascending order of the ID's if there is a tie.
bool cmp(record  &a , record & b){
	if(a.area != b.area) return a.area > b.area;
	else return a.id < b.id; 
}
int main(){
	init();
	int n;
	cin>>n;
	fill(cntState,cntState+100005,0);
	fill(cntArea,cntArea+100005,0);
	fill(exist,exist+100005,false);
	fill(number,number+100005,0);
	for(int i =0;i<n;i++){
		int id;
		cin>>id;
//		cout<<id<<endl;
		exist[id] = true;
		int father,mother;
		cin>>father>>mother;
		if(father!= -1){
			Union(father,id);
			exist[father] = true;
		}
		if(mother!=-1){
			Union(mother,id);
			exist[mother] = true;
		}
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			int child;
			cin>>child;
			Union(child,id);
			exist[child]=true;
		}
		double state,area;
		cin>>state>>area;
		cntState[findFather(id)]+=state;
		cntArea[findFather(id)]+=area;
	}
	int cnt = 0;
	for(int i =0;i<10000;i++){
		if(exist[i]){
			number[findFather(i)]++;
		}
	}
	vector<record> ans;
	for(int i =0;i<10000;i++){
		if(exist[i] && father[i]==i) {
			record tmp;
			tmp.id = i;
			tmp.number = number[i];
			tmp.state = double(cntState[i]/tmp.number);
			tmp.area = double(cntArea[i]/tmp.number);
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<endl;
	for(int i =0;i<ans.size();i++){
		printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].number,ans[i].state,ans[i].area);
	}
	return 0;
}
