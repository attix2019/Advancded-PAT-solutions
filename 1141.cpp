#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct testee{
	string id;
	int score;
	string ins;
};

struct institution{
	string id;
	int ns;
	int tws;
	int rank;
	int bscore,ascore,tscore;
	institution():ns(0),tws(0),bscore(0),ascore(0),tscore(0){
	}
};

map<string,institution> m;
vector<institution> vec;

bool cmp(institution & a,institution &b){
	if(a.tws != b.tws) return a.tws > b.tws;
	else if(a.ns != b.ns) return a.ns < b.ns;
	else return a.id < b.id;
}

string upper2lower(string s){
	for(int i =0;i<s.length();i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i]-=('A'-'a');
		}
	}
	return s;
}
int main(){
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		string id,ins;
		int score;
		cin>>id>>score>>ins;
		ins = upper2lower(ins);
		if(m.find(ins)==m.end()){
			institution tmp;
			tmp.id =ins;
			if(id[0]=='B'){
				tmp.bscore = score; 
			}else if(id[0]=='A'){
				tmp.ascore = score;
			}else{
				tmp.tscore = score;
			} 
			tmp.ns = 1;
			m[ins] = tmp;
		}else{
			if(id[0]=='B'){
				m[ins].bscore += score; 
			}else if(id[0]=='A'){
				m[ins].ascore += score;
			}else{
				m[ins].tscore += score;
			} 
			m[ins].ns++;
		}
	}
	for(map<string,institution>::iterator it=m.begin();it!=m.end();it++){
		it->second.tws = floor(double(it->second.bscore)/1.5 + it->second.ascore +
		double(it->second.tscore)*1.5);
		vec.push_back(it->second); 
	}
	sort(vec.begin(),vec.end(),cmp);
	cout<<vec.size()<<endl;
	vec[0].rank = 1;
	for(int i =1;i<vec.size();i++){
		if(vec[i].tws==vec[i-1].tws){
			vec[i].rank = vec[i-1].rank;
		}else{
			vec[i].rank = i+1;
		}
	}
	for(int i =0;i<vec.size();i++){
		printf("%d %s %d %d\n", vec[i].rank,vec[i].id.c_str(),vec[i].tws, vec[i].ns);
	}
	return 0;
} 
