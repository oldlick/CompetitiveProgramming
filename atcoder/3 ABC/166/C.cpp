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
	vector<ll> h(n);
	vector<ll> out(n);
	REP(i,n) cin>>h[i];
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		a--;b--;
		if(h[a]<h[b]){
			out[a]++;
		}else if(h[a]>h[b]){
			out[b]++;
		}else{
			out[a]++;
			out[b]++;
		}
	}
	ll ans=0;
	REP(i,n){
		if(out[i]==0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
