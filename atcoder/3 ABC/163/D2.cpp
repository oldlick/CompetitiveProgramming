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
#define MOD ((ll)1e9+7)
ll cal(ll n,ll m){
	return -m*(m+1)*(2*m+1)/6+(n+1)*m*(m+1)/2+m;
}
int main(){
	ll n; cin>>n;
	ll k; cin>>k;
	ll ans=0;
	ans=(cal(n,n+1)-cal(n,k-1))%MOD;
	cout<<ans<<endl;
	return 0;
}
