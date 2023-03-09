#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int fight(int m[],int h[],int i,int j){
	int kill=0;
	if(m[i]>=h[j]){
		kill=h[j];
	}else{
		kill=m[i];
	}
	m[i]-=kill;
	h[j]-=kill;
	return kill;
}

int main(){
	int num,m[100001]={},h[100000]={};
	long ans=0;
	cin>>num;
	for(int i=0;i<num+1;i++){
		cin>>m[i];
	}
	for(int i=0;i<num;i++){
		cin>>h[i];
	}
	for(int i=0;i<num;i++){
		ans+=fight(m,h,i,i);
		ans+=fight(m,h,i+1,i);
	}
	cout<<ans<<endl;
	return 0;
}