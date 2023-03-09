#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)


int find(vector<ll> L,int x){
	rep(i,L.size()){
		if(L[i]>x)return i;
	}
	return L.size()-1;
}
int rfind(vector<ll> L,int x){
	for(int i=L.size()-1;i>=0;i--){
		if(L[i]<x)return i;
	}
	return 0;
}

int main(){
	ll N,ans=0;
	cin>>N;
	vector<ll> d(N);
	rep(i,N) cin>>d[i];
	sort(d.begin(),d.end());
	rep(i,N){
		rep(j,N){
			if(i>=j)continue;
			int L=find(d,d[j]-d[i]);
			int R=rfind(d,d[j]+d[i]);
			//cout<<"["<<d[i]<<"]["<<d[j]<<"]"<<d[j]-d[i]<<"-"<<d[i]+d[j]<<endl;
			int inside=0;
			if(L<=i && i<=R)inside++;
			if(L<=j && j<=R)inside++;
			if(R-L+1-inside>0)ans+=R-L+1-inside;
			//cout<<R<<"-"<<L<<"-"<<inside<<":"<<R-L+1-inside<<endl;
		}
	}
	cout<<ans/3;
	return 0;
}
