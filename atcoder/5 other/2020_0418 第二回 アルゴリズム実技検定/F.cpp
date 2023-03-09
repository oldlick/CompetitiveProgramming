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
	map<ll,vector<ll>> c;
	REP(i,n){
		ll a,b;
		cin>>a>>b;
		a--;
		c[a].push_back(b);
	}
	priority_queue<ll> job;
	ll ans=0;
	REP(i,n){
		REP(j,c[i].size()){
			job.push(c[i][j]);
		}
		ans+=job.top();
		job.pop();
		cout<<ans<<endl;
	}
	return 0;
}
