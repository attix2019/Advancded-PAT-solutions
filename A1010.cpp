#include <iostream>
#include <string>

using namespace std;

long long toDecimal(string s, int radix){
	long long sum = 0;
	for(int i = 0; i<s.length();i++){
		if( s[i]>='0' && s[i]<='9')
			sum = (sum*radix) + (s[i]-'0');
		else if(s[i]>='a' && s[i]<='z')
			sum = (sum*radix) + (s[i]-'a'+10);			
	}
	return sum;
}

void findRadix(string s,long long decimalValue){
	int m = -1;
	for(int i =0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if((s[i]-'0')>m) m = s[i]-'0'+1;
		}else{
			if((s[i]-'a' + 10)>m) m = s[i]-'a'+11;			
		}
	}
	for(int r = m; r<=decimalValue+1;r++){
		long long temp = toDecimal(s,r);
		if(temp==decimalValue){
			cout<< r<<endl;	
		}else if(temp > decimalValue){
			cout<<"Impossible"<<endl;
			return;
		}else{
			continue;
		}
	}
	cout<<"Impossible"<<endl;
	return;
}

int main(){
	string n1,n2;
	long long tag,radix,temp;
	cin>>n1>>n2;
	scanf("%d%d",&tag,&radix);
	if(tag==1){
		temp = toDecimal(n1,radix);
		findRadix(n2,temp);
	}else{
		temp = toDecimal(n2,radix);
		findRadix(n1,temp);
	}
	return 0;
} 
