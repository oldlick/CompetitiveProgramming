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
	ll x; cin>>x;
	ll y; cin>>y;
	x--;y--;
	vector<vector<ll>> d(n,vector<ll>(n,INF));
	REP(i,n-1){
		d[i][i+1]=1;
		d[i+1][i]=1;
	}
	d[x][y]=1;
	d[y][x]=1;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

	vector<ll> ans(n);
	REP(i,n){
		FOR(j,i+1,n){
			ans[d[i][j]]++;
		}
	}
	FOR(i,1,n){
		cout<<ans[i]<<endl;
	}
	return 0;
}
