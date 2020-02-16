#include<iostream>
#include<vector>

using namespace std;

struct node{
	int id; 
	int data;
	int next;
//	node():next(-1){}
}; 

int main(){
	int head, n, k;
	int add,data,nextadd;
	
	node a[100005];
	vector<node> helper,vec;
	
	cin>>head>>n>>k;
	for(int i =0;i<n;i++){
		cin>>add>>data>>nextadd;
		a[add]={add,data,nextadd};
	}
	for(;head!=-1;head=a[head].next){
		helper.push_back(a[head]);	
	}	
	for(int i =0;i<helper.size();i++){
		if( helper[i].data<0) 
			vec.push_back(helper[i]);		
	}
	for(int i =0;i<helper.size();i++){
		if( helper[i].data>=0 && helper[i].data<=k) 
			vec.push_back(helper[i]);	
	}
	for(int i =0;i<helper.size();i++){
		if( helper[i].data>k) 
			vec.push_back(helper[i]);		
	}
	
	for(int i = 0;i<vec.size()-1;i++){
		printf("%05d %d %05d\n",vec[i].id,vec[i].data,vec[i+1].id);
	}
	printf("%05d %d -1\n",vec[vec.size()-1].id,vec[vec.size()-1].data);
	return 0;
}
