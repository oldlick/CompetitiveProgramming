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
	string s;
	cin>>s;
	vector<ll> num(s.size());
	REP(i,s.size()){
		num[i]=s[i]-'0';
	}

	vector<ll> mul(10000);
	REP(i,10000)mul[i]=2019*i;
	sort(mul.begin(),mul.end());
	ll ans=0;
	REP(i,10000){
		if(i==0){
			ans++;
		}else{
			if(mul[i]!=mul[i-1]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
