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
	ll m; cin>>m;
	vector<ll> a(m);
	REP(i,m) cin>>a[i];
	ll ans=0;
	REP(i,m)ans+=a[i];
	ans=n-ans;
	if(ans>=0){
		cout<<ans<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
