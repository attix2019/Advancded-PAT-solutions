#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		string s;
		cin>>s;
		int a = stoi(s);
		int len = s.length()/2;
		int b = stoi(s.substr(0,len));
		int c = stoi(s.substr(len,len));
		if(b*c==0||a%(b*c)!=0) {
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
