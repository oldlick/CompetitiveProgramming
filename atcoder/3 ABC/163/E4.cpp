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
	ll l=0,r=n-1,ans=0;
	REP(i,n){
		ll max_set=-1,max_idx=-1;
		REP(j,n){
			if(m[j].second==1)continue;
			if(max_idx==-1){
				max_idx=j;
				if(abs(max_idx-r)>abs(max_idx-l)){
					max_set=r;
				}else{
					max_set=l;
				}
			}else{
				if(m[j].first*abs(j-r)>m[max_idx].first*abs(max_idx-max_set)){
					max_idx=j;
					max_set=r;
				}
				if(m[j].first*abs(j-l)>m[max_idx].first*abs(max_idx-max_set)){
					max_idx=j;
					max_set=l;
				}
			}
		}
		m[max_idx].second=1;
		ans+=m[max_idx].first*abs(max_idx-max_set);
		if(max_set==r)r--;
		else l++;
		cout<<m[max_idx].first<<" "<<m[max_idx].first*abs(max_idx-max_set)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
