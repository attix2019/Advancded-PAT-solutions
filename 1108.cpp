#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
	int n;
	int cnt = 0;
	cin>>n;
	double sum = 0;
	double tmp;
	char a[50],b[50];
	for(int i = 0;i<n;i++){
		scanf("%s", a);
		sscanf(a,"%lf",&tmp);
		sprintf(b,"%.2f",tmp);
		bool legal = true;
		for(int j = 0;j<strlen(a);j++){
			if(a[j]!=b[j]) {
				legal = false;
			}
		}
		if(!legal || tmp >1000 || tmp<-1000){
			printf("ERROR: %s is not a legal number\n",a);
			continue;
		}else{
			sum+=tmp;
			cnt++;
		}	
	}
	if(cnt ==1 ){
		printf("The average of 1 number is %.2f", sum);
	}else if(cnt>1){
		printf("The average of %d numbers is %.2f", cnt, sum / cnt);
	} 
	else{
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
} 

///wrong version below 

//#include<cstdlib>
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<string>
//
//using namespace std;
//
//int main(){
//	int n;
//	int cnt = 0;
//	cin>>n;
//	double sum = 0;
//	double tmp;
//	char a[50],b[50];
//	for(int i = 0;i<n;i++){
//		scanf("%s", a);
//		sscanf(a,"%lf",&tmp);
//		sprintf(b,"%.2f",tmp);
//		bool legal = true;
//		for(int j = 0;j<strlen(a);j++){
//			if(a[j]!=b[j]) {
//				legal = false;
//			}
//		}
//		if(!legal || tmp >1000 || tmp<-1000){
//			printf("ERROR: %s is not a legal number\n",a);
//			continue;
//		}else{
//			sum+=tmp;
//			cnt++;
//		}	
//	}
//	if(cnt ==1){
//        printf("The average of 1 numbers is %.2lf",sum);
//	}else if(cnt>1){
//        printf("The average of %d numbers is %.2lf",cnt,sum/cnt);	
//	} else{
//	    printf("The average of 0 numbers is Undefined");	
//	}
//    return 0;
//} 
