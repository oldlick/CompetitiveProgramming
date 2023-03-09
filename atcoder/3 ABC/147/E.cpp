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
	ll h,w;
	cin>>h>>w;
	vector<vector<ll>> d(h,vector<ll>(w));
	REP(i,h){
		REP(j,w){
			cin>>d[i][j];
		}
	}
	REP(i,h){
		REP(j,w){
			ll tmp;
			cin>>tmp;
			d[i][j]=abs(d[i][j]-tmp);
		}
	}
	return 0;
}
