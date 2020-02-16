#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    if(sum<0) cout<<"-";
    string str = std::to_string(abs(a+b));
    string ans="";
    for(int i = 0;i<str.length();i++){
    	ans+=str[str.length()-1-i];
    	if((i+1)%3==0) ans+=string(",");
	}
	for(int i = ans.length()-1;i>=0;i--){
		cout<<ans[i];
	}
    return 0;
}
