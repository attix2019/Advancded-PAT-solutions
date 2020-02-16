#include<string>
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
	int d,n;
	cin>>d>>n;
	string s = to_string(d); 
	for(int i =1;i<=n;i++){
		string tmp;
		int cnt;
		for(int j =0;j<s.length()-1;){
			cnt = 1;
			while(s[j]==s[j+1]){
				cnt++;
				j++;
			}
			tmp+=(s[j]+to_string(cnt));
		}
		if(s[s.length()-1]==s[s.length()-2]){
			
		}else{
			tmp+=(s[s.length()-1]+"1");
		}
		if(i==n) break;
		s= tmp;
	}
	cout<<s<<endl;
	return 0;
}
