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
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

typedef long long ll;
#define INF 1e18

const ll MOD=1000000007;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll comb(ll n, ll r){
	ll ans=1;
	REP(i,r){
		ans=(ans*(n-i))%MOD;
		ans=ans*modinv(i+1,MOD);
		ans%=MOD;
	}
	return ans;
}
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main(){
	ll n; cin>>n;
	ll a; cin>>a;
	ll b; cin>>b;
	ll ans=modpow(2,n)-1;
	ans=(ans+MOD-comb(n,a))%MOD;
	//cout<<comb(n,a)<<endl;
	ans=(ans+MOD-comb(n,b))%MOD;
	//cout<<comb(n,b)<<endl;
	cout<<ans<<endl;
	return 0;
}