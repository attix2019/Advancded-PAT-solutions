#include <iostream> 
#include <string>
#include <vector>

using namespace std;

bool isParli(vector<long long int> & v){
	for(int i =0,j=v.size()-1; i<j;i++,j-- ){
		if(v[i]!=v[j]) return false;
	}
	return true;
}
int main(){
	long long n, b;
	scanf("%lld%lld",&n,&b);
	vector<long long int > v;
	while(n!=0){
		v.push_back(n%b);
		n/=b;
	} 
	if(!isParli(v)) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	for(int i = v.size()-1;i>0;i--){
		cout<<v[i]<<" ";
	}
	cout<<v[0]<<endl;
	return 0;
}
