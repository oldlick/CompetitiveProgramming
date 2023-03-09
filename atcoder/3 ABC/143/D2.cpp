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
#define rep(i,j,n) for(int i=j;i<n;i++)


int find(vector<ll> L,int x){
	rep(i,0,L.size()){
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
	rep(i,0,N) cin>>d[i];
	sort(d.begin(),d.end());
	rep(i,0,N){
		rep(j,i+1,N){
			rep(k,j+1,N){
				if(d[k]-d[j]>=d[i])continue;
				if(d[k]+d[j]<=d[i])continue;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
