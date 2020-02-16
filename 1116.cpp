#include<string>
#include<map>
#include<iostream>
#include<cmath>

using namespace std;

map<string,int> m;
map<string,bool> checked;

bool isprime(int n){
    for(int i =2;i<=sqrt(n);i++){
        if((n%i)==0) return false;
    }
    return true;
}

void award(string query){
    if(m.find(query)==m.end()){
        cout<<query<<": Are you kidding?"<<endl;
        return ;
    }
    if(checked.find(query)!=checked.end()){
        cout<<query<<": Checked"<<endl;
        return ;
    }
    checked[query] = true;
//cout<<m[query]<<endl;
    if(m[query]==1){
        cout<<query<<": Mystery Award"<<endl;
        return ;
    }
    if(isprime(m[query])){
        cout<<query<<": Minion"<<endl;
        return ;      
    }
    cout<<query<<": Chocolate"<<endl;
}
int main(){
	int n;
    cin>>n;//id to rank
    for(int i =1;i<=n;i++){
        string tmp;
        cin>>tmp;
        m[tmp] = i;
    }
    int k;
    cin>>k;
    for(int i =0;i<k;i++){
        string query;
        cin>>query;
        award(query);
    }
    return 0;
}
