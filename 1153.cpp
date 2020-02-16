#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
int cntsite[1005];
struct card{
	string level;
	string site;
	string date;
	string id;
	int score;
	card(string level1,string site1,string date1,string id1,int score1):
	level(level1),site(site1),date(date1),id(id1),score(score1){
	}
};
//19:50 start
map<string,set<card> > m1,m2,m3;

bool cmp1(card& a, card& b){
	if(a.score!=b.score) return  a.score > b.score;
	else return (a.level+a.site+a.date+a.id) < (b.level+b.site+b.date+b.id);
}

bool cmp3(card& a, card& b){
	if(cntsite[atoi(a.site.c_str())]!= cntsite[atoi(b.site.c_str())])
		return cntsite[atoi(a.site.c_str())]> cntsite[atoi(b.site.c_str())];
	else return a.site < b.site;
}


int main(){
	int n,m;
	cin>>n>>m;
	fill(cntsite,cntsite+1005,0);
	for(int i = 0;i<n;i++){
		string number;
		int score;
		string level = number.substr(0,1);
		string site  = number.substr(1,3);
		cntsite[atoi(site.c_str())]++;
		string date = number.substr(4,6);
		string id = number.substr(10,3);
		card tmpcard(level,site,date,id,score);
		if(m1.find(level)==m1.end()){
			set<card> tmps;
			tmps.insert(tmpcard);
			m1[level] = tmps;
		}else{
			m1[level].insert(tmpcard);
		}
//
		if(m2.find(site)==m2.end()){
			set<card> tmps;
			tmps.insert(tmpcard);
			m1[site] = tmps;
		}else{
			m1[site].insert(tmpcard);
		}
//
		if(m1.find(date)==m3.end()){
			set<card> tmps;
			tmps.insert(tmpcard);
			m1[date] = tmps;
		}else{
			m1[date].insert(tmpcard);
		}
	}	
	for(int i =0;i<m;i++){
		int type;
		string term;
		cin>>type>>term;
		vector<card> ans;
		if(type==1){
			if(m1.find(term)==m1.end()){
				cout<<"NA"<<endl;
				continue;
			}else{
				for(set<card>::iterator it = m1[term].begin();it!=m1[term].end();it++){
					ans.push_back(*it);
				}
				sort(ans.begin(),ans.end(),cmp1);
				for(int j=0;j<ans.size();j++){
					cout<<	ans[i].id<<" "<<ans[i].score<<endl;
				}
			}
		}
		//if type ==2
		if(type==2){
			if(m2.find(term)==m2.end()){
				cout<<"NA"<<endl;
				continue;
			}else{
				for(set<card>::iterator it = m2[term].begin();it!=m2[term].end();it++){
					ans.push_back(*it);
				}
				int sum = 0;
				for(int j=0;j<ans.size();j++){
					sum+=ans[i].score;
				}
				cout<<ans.size()<<" "<<sum<<endl;
			}
		}
		//if type ==3
		if(type==3){
			if(m3.find(term)==m3.end()){
				cout<<"NA"<<endl;
				continue;
			}else{
				for(set<card>::iterator it = m3[term].begin();it!=m3[term].end();it++){
					ans.push_back(*it);
				}
				sort(ans.begin(),ans.end(),cmp3);
				for(int j=0;j<ans.size();j++){
					cout<<	ans[i].id<<" "<<ans[i].score<<endl;
				}
			}
		}
	}
	return 0;
} 
