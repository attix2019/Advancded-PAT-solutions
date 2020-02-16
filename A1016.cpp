#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct mytime{
	int month,day,hour,minute;
};
struct record{
	char name[20];
	mytime time;
	char mark[10];
};

bool cmp1(const &record a, const &record b){
	
}

int main(){
	int chargetable[24];// chargetable[i]: fee between i and i+1 o'clock
	for(int i =0;i<24;i++){
		scanf("%d",&chargetable[i]);
	}
	int n;
	scanf("%d",&n);
	vector<record> v;
	for(int i = 0; i<n;i++){
		record r;
		scanf("%s", &r.name);
		scanf("%d%d%d%d",&r.time.month,&r.time.day,&r.time.hour,&r.time.minute);
		scanf("%s",r.mark);
		v.push_back(r);
	}
	sort(v.begin(),v.end(),cmp1);
	for(int i = 0;i<n; ){
		while(strcmp(v[i].mark,"on-line")!=0){
			i++;
		}
		int on = i;
		while(strcmp(v[i].mark,"off-line")!=0){
			i++;
		}
		int off = i;
		user = string(v[on].name);
		printf("%s",v[on].name);
	}
	return 0;
} 
