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
ll len(ll n){
	ll ans=0;
	while(n!=0){
		n/=10;
		ans++;
	}
	return ans;
}

int main(){
	string n; cin>>n;
	ll k; cin>>k;
	vector<ll> m(n.size());
	REP(i,n.size()) m[i]=n[i]-'0';
	
	return 0;
}
