#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

#define MOD (ll)(1e9+7);

map<ll,ll> fact(ll a){
	map<ll,ll> ans;
	while(a!=1){
		FOR(i,2,a+1){
			while(a%i==0){
				a/=i;
				ans[i]++;
			}
		}
	}
	return ans;
}

map<ll,ll> calcLcm(vector<ll> a){
	map<ll,ll> ans;
	for(auto it:a){
		while(it!=1){
			FOR(i,2,it+1){
				ll tmp=0;
				while(it%i==0){
					it/=i;
					tmp++;
				}
				if(tmp!=0){
					ans[i]=max(ans[i],tmp);
				}
			}
		}
	}
	return ans;
}

ll factToInt(map<ll,ll> a){
	ll ans=1;
	for(auto it:a){
		REP(i,it.second){
			ans*=it.first;
			ans%=MOD;
		}
	}
	return ans;
}

int main(){
	ll n; cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<map<ll,ll>> f(n);
	map<ll,ll> lcm=calcLcm(a);
	ll ans=0;
	REP(i,n){
		map<ll,ll> tmpLcm=lcm;
		map<ll,ll> i_fact=fact(a[i]);
		for(auto it:i_fact){
			tmpLcm[it.first]-=it.second;
		}
		ans+=factToInt(tmpLcm);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
