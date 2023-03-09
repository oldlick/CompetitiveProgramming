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
	ll a; cin>>a;
	ll b; cin>>b;
	if(a==0 && b==0){
		cout<<0<<endl;
		return 0;
	}
	ll ans=0;
	ans=(n/(a+b))*a;
	ans+=(n%(a+b))<a?(n%(a+b)):a;
	cout<<ans<<endl;
	return 0;
}
