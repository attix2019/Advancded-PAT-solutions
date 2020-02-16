#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

struct customer{
	int length;
	int endtime;
	customer(): endtime(0){
	} 
};

customer cus[1005];

int main(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	for(int i =1;i<= k;i++){
		cin>>cus[i].length;
	} 
	deque<customer> windows[n];
	for(int i = 0; i< min(k,n*m);i++){
		int windownum =i%n;
		int customer_before_i = i/n;
		for(int j=0;j<customer_before_i;j++){
			cus[i+1].endtime += windows[windownum][j].length;
		}
		cus[i+1].endtime+=cus[i+1].length;
		windows[windownum].push_back(cus[i+1]);
	}
	for(int i =m*n+1 ; i<=k;i++){
		//find smallest between windows[i][0] and record, pop it
		int minid = 0;
		int mintime = windows[0][0].length;
		for(int j = 1;j<n;j++){
			if(windows[j][0].length < mintime ){
				minid = j;
				mintime = windows[j][0].length;
			}
		}
		//pop windows[minid][0],and induct same time on each window[][0]
		cus[i].endtime = windows[minid][windows[minid].size()-1].endtime+cus[i].length;
		windows[minid].push_back(cus[i]);
		windows[minid].pop_front();
		for(int j = 0;j<n;j++){
			if(j!=minid ){
				windows[j][0].length -= mintime;
			}
		}

	}
	for(int i = 0;i<q;i++){
		int query;
		cin>>query;
		if(cus[query].endtime - cus[query].length >=540){
			cout<<"Sorry"<<endl;
		}else{
			int h = 8+cus[query].endtime/60;
			int m = cus[query].endtime%60;
			printf("%02d:%02d\n",h,m);
		}
	}
	return 0; 
}
