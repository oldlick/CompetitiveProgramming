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

#define MOD 2019

int main(){
	string s;
	cin>>s;
	ll n=s.size();
	ll t[2019]={};//「左からi~n(i:0~n)の数値」を2019で割ったあまりが何個あるか
	t[0]++;
	ll tmp=0,power=1;
	REPR(i,n){
		tmp+=(s[i]-'0')*power;
		tmp%=MOD;
		t[tmp]++;
		power*=10;
		power%=MOD;
	}
	ll ans=0;
	REP(i,MOD){
		ans+=t[i]*(t[i]-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
