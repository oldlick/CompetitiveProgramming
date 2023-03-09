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

vector<ll> a;
vector<ll> b;
vector<ll> f;

ll next(ll t){
	t++;
	ll minidx=-1;
	REP(i,f.size()){
		if(f[i]==0){
			if((a[minidx])*t+b[minidx]>a[i]*t+b[i])minidx=i;
			if((a[minidx])*t+b[minidx]==a[i]*t+b[i]){
				minidx=(a[minidx]>a[i]?minidx:i);
			}
		}
	}
	if(minidx==-1)return -1;
	f[minidx]=1;
	return t+a[minidx]*t+b[minidx];
}

int main(){
	ll n; cin>>n;
	ll t; cin>>t;
	a.resize(n);
	b.resize(n);
	f.resize(n);
	REP(i,n){
		cin>>a[i];
		cin>>b[i];
	}
	ll i=0;
	ll ans=0;
	while(1){
		i=next(i);
		if(i==-1)break;
		if(i>t)break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
