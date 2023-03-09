#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	ll N,X;
	cin>>N>>X;
	ll max=1;
	while(max<=X){
		max=max<<1;
	}
	vector<ll> a(N);
	vector<ll> ans(N);
	vector<ll> data;
	ll XOR=0;
	for(int i=0;i<N;i++){
		cin>>a[i];
		ans[i]=a[i];
		if(ans[i]==-1){
			ans[i]=0;
			data.push_back(i);
		}
		XOR^=ans[i];
	}
	
	ll put=XOR^X;
	if(put==0){
		goto Yes;
	}else if(put<=X){
		if(data.size()>=1){
			ans[data[0]]=put;
			goto Yes;
		}
		else goto No;
	}else if(put<max){
		if(data.size()>=2){
			ans[data[0]]=X;
			ans[data[1]]=X^put;
			goto Yes;
		}
		else goto No;
	}else{
		goto No;
	}
	
	Yes:
		for(int i=0;i<N;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	No:
		cout<<"-1"<<endl;
		return 0;
}