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

int main(){
	ll n; cin>>n;
	ll k; cin>>k;
	ll ans=0;
	FOR(i,k,n+2){
		ans+=(i*(n-i+1)+1)%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
