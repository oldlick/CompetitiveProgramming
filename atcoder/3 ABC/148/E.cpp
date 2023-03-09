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

int main(){
	ll n; cin>>n;
	ll p; cin>>p;
	string s;
	cin>>s;
	if(p==2 || p==5){
		ll ans=0;
		REP(i,n){
			if((s[i]-'0')%p==0){
				ans+=i+1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	map<ll,ll> t;
	t[0]++;
	ll tmp=0,power=1;
	REPR(i,n){
		tmp+=(s[i]-'0')*power;
		tmp%=p;
		t[tmp]++;
		power*=10;
		power%=p;
		//cout<<tmp<<endl;
	}
	ll ans=0;
	for(auto &it:t){
		ans+=it.second*(it.second-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
