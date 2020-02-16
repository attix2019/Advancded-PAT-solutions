#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

bool isprime(long int n){
	if(n==0) return false;
	if(n==1) return false;
	if(n==2) return true;
	for(int i = 2;i<=sqrt(n)+1;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int L,K;
	cin>>L>>K;
	string s;
	cin>>s;
	for(int i = 0;i<=L-K;i++){
		string tmp = s.substr(i,K);
		if(isprime(atoi(tmp.c_str()))){
			cout<<tmp.c_str()<<endl;
			return 0;
		} 
	} 
	cout<<404<<endl;
	return 0;
} 
