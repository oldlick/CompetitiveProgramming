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
	vector<pair<ll,ll>> m(n);
	REP(i,n) {
		m[i].first=a[i];
		m[i].second=0;
	}
	ll mid=n/2;
	ll ans=0;
	REP(i,mid){
		ll max_idx=-1;
		REP(j,n){
			if(i==j)continue;
			if(m[j].second==1)continue;
			if(max_idx==-1)max_idx=j;
			else if(m[j].first*abs(j-i)>m[max_idx].first*abs(max_idx-i))max_idx=j;
		}
		m[max_idx].second=1;
		ans+=m[max_idx].first*abs(max_idx-i);
		cout<<m[max_idx].first<<" "<<m[max_idx].first*abs(max_idx-i)<<endl;
	}
	for(int i=n-1;i>=mid;i--){
		ll max_idx=-1;
		REP(j,n){
			if(i==j)continue;
			if(m[j].second==1)continue;
			if(max_idx==-1)max_idx=j;
			else if(m[j].first*abs(j-i)>m[max_idx].first*abs(max_idx-i))max_idx=j;
		}
		m[max_idx].second=1;
		ans+=m[max_idx].first*abs(max_idx-i);
		cout<<m[max_idx].first<<" "<<m[max_idx].first*abs(max_idx-i)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
