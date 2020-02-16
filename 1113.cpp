#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a[100005];

int main(){
//	cout<<2333+666+555+99+46-46-23-10-8-1<<endl;
    int n;
    cin>>n;
    int sum = 0;
    for(int i =0;i<n;i++){
        cin>>a[i];
//        cout<<a[i]<<" ";
        sum+=a[i];
    }
//    cout<<sum<<endl;
//    cout<<endl;
    sort(a,a+n);
    int k;
    if(n%2==0){
        cout<<"0 ";
        k=n/2;
    }else{
        cout<<"1 ";
        k=(n-1)/2;
    }
    int small = 0;
    for(int i =0;i<k;i++){
//    	cout<<a[i]<<" ";
        small += a[i];
    }
//    cout<<small<<endl;
//    cout<<endl;
    cout<<sum - small*2;
}
