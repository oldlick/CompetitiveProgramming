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
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> V(n);
	REP(i,n){
		V[i]=a[i]+i+1;
	}
	vector<pair<ll,ll>> v(n);
	REP(i,n){
		v[i].first=a[i]-i-1;
		v[i].second=i;
	}
	sort(v.begin(),v.end());
	ll ans=0;
	REP(i,n){
		auto it1=lower_bound(v.begin(),v.end(),pair<ll,ll> (-V[i],-1));
		if(it1==v.end())continue;
		if(it1->first==-V[i]){
			auto it2=upper_bound(v.begin(),v.end(),pair<ll,ll> (-V[i],n+10));
			ans+=it2-it1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
