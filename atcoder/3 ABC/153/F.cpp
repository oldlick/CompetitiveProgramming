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
	ll d; cin>>d;
	ll a; cin>>a;
	vector<pair<ll,ll>> xh(n);
	REP(i,n) {
		cin>>xh[i].first;
		cin>>xh[i].second;
	}
	sort(xh.begin(),xh.end());
	ll sum=0;
	REP(i,n){
		if(xh[i].second<=0)continue;
		ll tmp=xh[i].second/a+(xh[i].second%a!=0);
		ll at=tmp*a;
		FOR(j,i+1,n){
			if(xh[j].first<=xh[i].first+2*d){
				xh[j].second-=at;
			}else{
				break;
			}
		}
		sum+=tmp;
	}
	cout<<sum<<endl;
	return 0;
}
