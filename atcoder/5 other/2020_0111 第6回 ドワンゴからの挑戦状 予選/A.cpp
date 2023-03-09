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
	ll n;
	cin>>n;
	vector<string> s(n);
	vector<ll> t(n);
	REP(i,n){
		cin>>s[i];
		cin>>t[i];
	}
	string x;
	cin>>x;
	auto it=find(s.begin(),s.end(),x);
	ll st=it-s.begin();
	ll ans=0;
	FOR(i,st+1,n){
		ans+=t[i];
	}
	cout<<ans<<endl;
	return 0;
}
