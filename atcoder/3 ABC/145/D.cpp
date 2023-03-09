#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18
ll M=1000000007;
vector<ll> fac(1100001);
vector<ll> ifac(1100001);
ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}
int main(){
	ll X,Y;
	cin>>X>>Y;
	if(X>Y){
		ll tmp=X;
		X=Y;
		Y=tmp;
	}
	if((X+Y)%3!=0){
		cout<<"0";
		return 0;
	}
	if(X==0 && Y==0){
		cout<<"1";
		return 0;
	}
	if(X==0){
		cout<<"0";
		return 0;
	}
	if(Y>X*2){
		cout<<"0";
		return 0;
	}
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<1100000; i++){
        fac[i+1] = fac[i]*(i+1) % M;
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M;
    }
	cout<<comb((X+Y)/3,X-(X+Y)/3)%M;
	return 0;
}