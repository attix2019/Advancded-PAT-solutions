#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

struct record{
	string id;
	string in,out;
};

vector<record> v;

bool cmp1(record & a,record &b){
	if(a.in.substr(0,2)!=b.in.substr(0,2)) return stoi(a.in.substr(0,2))<stoi(b.in.substr(0,2));
	if(a.in.substr(3,2)!=b.in.substr(3,2))return stoi(a.in.substr(3,2))<stoi(b.in.substr(3,2));
	if(a.in.substr(6,2)!=b.in.substr(6,2))return stoi(a.in.substr(6,2))<stoi(b.in.substr(6,2));
}

bool cmp2(record & a,record &b){
	if(a.out.substr(0,2)!=b.out.substr(0,2)) return stoi(a.out.substr(0,2))>stoi(b.out.substr(0,2));
	if(a.out.substr(3,2)!=b.out.substr(3,2))return stoi(a.out.substr(3,2))>stoi(b.out.substr(3,2));
	if(a.out.substr(6,2)!=b.out.substr(6,2))return stoi(a.out.substr(6,2))>stoi(b.out.substr(6,2));
}

//int time2int(string time){
//	return stoi(time.substr(0,2))*3600+stoi(time.substr(3,2))*60+stoi(time.substr(6,2));
//}
//
//bool cmp1(record & a,record &b){
//	return time2int(a.in)
//}
//bool cmp2(record & a,record &b){
//
//}
int main(){
	int n;
	cin>>n;
//	cout<<"s"<<(string("20")>string("1"))<<endl;
	for(int i =0;i<n;i++){
		record tmp;
		cin>>tmp.id>>tmp.in>>tmp.out;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp1);
	cout<<v[0].id<<" ";
	sort(v.begin(),v.end(),cmp2);	
	cout<<v[0].id<<endl;
	return 0;
} 
