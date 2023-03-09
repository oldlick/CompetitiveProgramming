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
	vector<vector<ll>> a(3,vector<ll>(3,0));
	REP(i,3){
		REP(j,3){
			cin>>a[i][j];
		}
	}
	ll n; cin>>n;
	vector<ll> b(n);
	REP(i,n) cin>>b[i];

	
	REP(i,3){
		REP(j,3){
			REP(k,n){
				if(a[i][j]==b[k])a[i][j]=-1;
			}
		}
	}
	int f=0;
	REP(i,3){
		f=1;
		REP(j,3){
			if(a[i][j]!=-1)f=0;
		}
		if(f==1)goto YES;
	}
	REP(i,3){
		f=1;
		REP(j,3){
			if(a[j][i]!=-1)f=0;
		}
		if(f==1)goto YES;
	}
	
	f=1;
	REP(i,3){
		if(a[i][i]!=-1)f=0;
	}
	if(f==1)goto YES;
	
	f=1;
	REP(i,3){
		if(a[i][2-i]!=-1)f=0;
	}
	if(f==1)goto YES;


	cout<<"No"<<endl;
	return 0;
	YES:
	cout<<"Yes"<<endl;
	return 0;
}
