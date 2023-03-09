#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int index_max(int a[],int num){
	int max=a[0];
	int index=0;
	for(int i=1;i<num;i++){
		if(max<a[i]){
			max=a[i];
			index=i;
		}
	}
	return index;
}

int side(int a[],int p,int num){
	if(p==0){
		return a[num-1]+a[1];
	}else if(p==num-1){
		return a[num-2]+a[0];
	}else{
		return a[p-1]+a[p+1];
	}
}

void show(int a[],int num){
	for(int i=0;i<num;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int cheack(int a[],int b[],int num){
	for(int i=0;i<num;i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main(){
	int num;
	int a[200000]={};
	int b[200000]={};
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	for(int i=0;i<num;i++){
		cin>>b[i];
	}
	
	int ans=0;
	int p,tmp,now=1;
	while(now!=0){
		p=index_max(b,num);
		now=b[p]/side(b,p,num);
		b[p]-=side(b,p,num)*now;
		ans+=now;
		//show(b,num);
	}
	
	
	if(cheack(a,b,num)==1){
		cout<<ans;
	}else{
		cout<<"-1";
	}
	return 0;
}
