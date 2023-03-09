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

int reverse(int a[],int p,int num){
	if(p==0){
		return a[0]-a[num-1]-a[1];
	}else if(p==num-1){
		return a[num-1]-a[num-2]-a[0];
	}else{
		return a[p]-a[p-1]-a[p+1];
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
	while(1){
		int p=index_max(b,num);
		int tmp=reverse(b,p,num);
		if(tmp<a[p]){
			if(cheack(a,b,num)==0){
				cout<<"-1";
				break;
			}else{
				cout<<ans;
				break;
			}
		}
		b[p]=tmp;
		ans++;
		show(b,num);
	}
	return 0;
}
