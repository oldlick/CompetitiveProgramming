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
#define MOD ((ll)(1e9+7))

int main(){
	ll N;
	cin>>N;
	vector<ll> a(N);
	REP(i, N) cin >> a[i];
	vector<ll> l(60,0);
	REP(i,N){
		REP(j,60){
			if(((a[i]>>j)&1)==1){
				l[j]++;
			}
		}
	}
	ll ans=0;
	ll power=1;
	REP(j,60){
		ll tmp;
		tmp=(l[j]*(N-l[j]))%MOD;
		tmp=(tmp*power)%MOD;
		ans=(ans+tmp)%MOD;
		power*=2;
		power%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
