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
	vector<pair<ll,pair<ll,ll>>> m(n);
	REP(i,n) {
		m[i].first=a[i]*max(i,n-i-1);
		m[i].second.first=a[i];
		m[i].second.second=i;
	}
	sort(m.rbegin(),m.rend());
	ll l=0,r=n-1,ans=0;
	REP(i,n){
		double mid=(double)(l+r)/2;
		ll set=0;
		if(m[i].second.second==mid && i+1!=n){
			if(m[i].second.second>m[i+1].second.second){
				set=l;
			}else{
				set=r;
			}
		}else{
			if(m[i].second.second>mid){
				set=l;
			}else{
				set=r;
			}
		}
		ans+=abs(m[i].second.second-set)*m[i].second.first;
		//cout<<abs(m[i].second.second-set)*m[i].second.first<<" "<<set<<" "<<m[i].second.first<<endl;
		if(set==r)r--;
		if(set==l)l++;
	}
	cout<<ans<<endl;
	return 0;
}
