#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int isxor(int a[],int num,int j){
	int ans=0;
	for(int i=j;i<=num;i+=j){
		if(a[i]==1){
			ans^=1;
		}
	}
	return ans;
}
int main(){
	int num=0,a[200001]={},ans[200001]={};
	cin>>num;
	for(int i=1;i<=num;i++){
		cin>>ans[i];
	}
	for(int i=num;i>0;i--){
		ans[i]=isxor(ans,num,i)^a[i];
		if(ans[i]==1)ans[0]++;
	}
	cout<<ans[0]<<endl;
	for(int i=1;i<=num;i++){
		if(ans[i]==1)cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}