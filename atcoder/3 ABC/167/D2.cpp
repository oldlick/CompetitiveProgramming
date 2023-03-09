#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll n; cin>>n;
	ll k; cin>>k;
	vector<ll> a(n);
	REP(i,n){
		cin>>a[i];
		a[i]--;
	}
	vector<vector<ll>> next(n,vector<ll>(0));
	for(ll i=0;;i++){
		if(pow(2,i)>k)break;
		REP(j,n){
			next[j].push_back(0);
			if(i==0)next[j][i]=a[j];
			else next[j][i]=next[next[j][i-1]][i-1];
		}
	}/*
	REP(i,(signed)next.size()){
		cout<<"next: ";
		REP(j,(signed)next[i].size()){
			cout<<next[i][j]<<" ";
		}
		cout << endl;
	}*/
	ll cur=0;
	for(ll i=0;;i++){
		if(k<=0)break;
		if(k%2==1){
			cur=next[cur][i];
		}
		k/=2;
	}
	cout<<cur+1<<endl;
	return 0;
}
/*

6 727202214173249351
6 5 2 5 3 2

6 3
6 5 2 5 3 2

*/
