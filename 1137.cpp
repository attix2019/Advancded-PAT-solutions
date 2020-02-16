#include<map>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct student{
	string id;
	int gp,gmid,gfinal,g;
	student() :gp(-1),gmid(-1),gfinal(-1),g(-1){}
};

//student a[10005];
//int cnt = 0;

vector<student> ans;


bool cmp(student &a, student& b){
	if(a.g != b.g) return a.g>b.g;
	else return a.id < b.id;

}

int main(){
	int p,m1,n;
	scanf("%d%d%d",&p,&m1,&n);
	map<string,student> m;
	for(int i =0;i<p;i++){
		student tmp;
		cin>>tmp.id>>tmp.gp;
		m[tmp.id] = tmp; 
	}
	for(int i =0;i<m1;i++){
		string tmpid;
		int tmpgmid;
		cin>>tmpid>>tmpgmid;
		if(m.find(tmpid)!=m.end()){
			m[tmpid].gmid = tmpgmid;
		}else{
			student tmp;
			tmp.id= tmpid;
			tmp.gmid = tmpgmid;
			m[tmpid] = tmp;
		}
	}
	for(int i =0;i<n;i++){
		string tmpid;
		int tmpgfinal;
		cin>>tmpid>>tmpgfinal;
		if(m.find(tmpid)!=m.end()){
			m[tmpid].gfinal= tmpgfinal;
		}else{
			student tmp;
			tmp.id= tmpid;
			tmp.gfinal = tmpgfinal;
			m[tmpid] = tmp;
		}		
	}
	for(map<string,student>::iterator it = m.begin();it!=m.end();it++){
		if(it->second.gp<200 || it->second.gfinal == -1) continue;
		if(it->second.gfinal != -1 && it->second.gmid != -1){
			if(it->second.gmid > it->second.gfinal){
				it->second.g = round(0.4 * it->second.gmid + 0.6*it->second.gfinal);
			}else{
				it->second.g = it->second.gfinal;
			}
		}
		if(it->second.gfinal != -1 && it->second.gmid == -1){
			it->second.g = it->second.gfinal;
		}
		if(it->second.g < 60) continue;
		ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i =0;i<ans.size();i++){
//		cout<<ans[i].id<<;
		printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].gp,ans[i].gmid,
		ans[i].gfinal,ans[i].g) ;
	} 
	return 0;
}
