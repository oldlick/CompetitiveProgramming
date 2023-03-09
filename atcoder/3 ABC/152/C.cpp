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
	ll min,ans=0;
	REP(i,n){
		ll tmp;
		cin>>tmp;
		if(i==0){
			min=tmp;
			ans++;
			continue;
		}
		if(tmp<min){
			min=tmp;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
