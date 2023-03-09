#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
void max(int a[],int num,int &max1,int &max2){
	max1=0;max2=0;
	for(int i=0;i<num;i++){
		if(max1<a[i] || i==0){
			max2=max1;
			max1=a[i];
		}else if(max2<a[i] || i==1){
			max2=a[i];
		}
	}
}
int main(){
	int num=0,a[200000]={},max1,max2;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	max(a,num,max1,max2);
	for(int i=0;i<num;i++){
		if(a[i]==max1){
			cout<<max2;
		}else{
			cout<<max1;
		}
		cout<<endl;
	}
	return 0;
}
