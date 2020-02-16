#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std; 

string tmp1[13]= {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", 
"oct", "nov", "dec"}; //low 
string tmp2[13]= {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", 
"lok", "mer", "jou"}; // high

map<string,int> high,low;
	
void earth2mars(string s){
	int value = atoi(s.c_str());
	int lowdigit= value%13;
	int highdigit = value/13;
	string ans="";
	string s1 = tmp2[highdigit];
	string s2= tmp1[lowdigit];
	if     (highdigit!=0 &&  lowdigit!=0) ans = s1+" "+s2;
	else if(highdigit!=0 && lowdigit ==0) ans = s1;
	else if(highdigit==0 && lowdigit !=0)ans = s2;
	else if(highdigit==0 && lowdigit ==0)ans= s2;
	cout<<ans<<endl;
}

void mars2earth(string s){
	int ans = 0 ;
	if(s.length()>4){
		string h = s.substr(0,3);
		string l = s.substr(4,3);
		ans= high[h]*13 + low[l];
	}else{
		if(high.find(s)!=high.end()) ans = high[s]*13;
		else ans = low[s];
	}
	cout<<ans<<endl; 
}

int main(){	
	for(int i =0;i<13;i++){
		low[tmp1[i]]=i;
	}
	for(int i =1;i<13;i++){
		high[tmp2[i]]=i;
	}
	int n;
	scanf("%d%*c",&n);
	for(int i =0;i<n;i++){
		string tmp;
		getline(cin,tmp);
		if(tmp[0]>='0' && tmp[0]<='9') earth2mars(tmp);
		else mars2earth(tmp);
	}
	return 0;
}



/*
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std; 

string tmp1[13]= {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", 
"oct", "nov", "dec"};
string tmp2[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", 
"syy", "lok", "mer", "jou"};

map<string,int> high,low;
	
void earth2mars(string s){
	int value = atoi(s.c_str());
	if(value==0){
		cout<<"tret"<<endl;
        return;
	}
	int lowdigit= value%13;
	int highdigit = value/13;
	string ans="";
	if(highdigit!=0 && lowdigit!=0) ans=tmp2[highdigit]+" "+tmp1[lowdigit];
    if(highdigit!=0 && lowdigit==0) ans+=tmp2[highdigit];
	if(highdigit==0 && lowdigit!=0) ans=tmp1[lowdigit];
	cout<<ans<<endl;
}

void mars2earth(string s){
	int ans = 0 ;
	if(s.length()>4){
		string h = s.substr(0,3);
		string l = s.substr(4,3);
		ans= high[h]*13 + low[l];
	}else{
		if(high.find(s)!=high.end()) ans = high[s]*13;
		else ans = low[s];
	}
	cout<<ans<<endl; 
}

int main(){	
	for(int i =0;i<13;i++){
		low[tmp1[i]]=i;
	}
	for(int i =1;i<13;i++){
		high[tmp2[i]]=i;
	}
	int n;
	scanf("%d",&n);
	getchar();
	for(int i =0;i<n;i++){
		string tmp;
		getline(cin,tmp);
		if(tmp[0]>='0' && tmp[0]<='9') earth2mars(tmp);
		else mars2earth(tmp);
	}
	return 0;
}

*/
