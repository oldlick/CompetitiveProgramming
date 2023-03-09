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
#define MOD ((ll)(1e9)+7)

ll hoge(ll a){
	ll ans=1;
	ll lim=sqrt(a)+1;
	FOR(i,2,lim){
		if(a%i==0){
			ans*=i;
		}
		while(a%i==0){
			a/=i;
		}
	}
	return ans;
}

int main(){
	ll k; cin>>k;
	ll n; cin>>n;
	ll ans=0;
	vector<ll> ans_p(k);
	FOR(i,1,k+1){
		ll tmp=k/i;
		tmp=pow(tmp,n-1);
		tmp%=MOD;
		tmp*=i/hoge(i)-1;
		tmp%=MOD;

		tmp*=k/i;
		ans+=tmp+pow(k,n);
	}
	cout<<ans<<endl;
	return 0;
}
