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


ll n,m,x;
vector<vector<ll>> c;

ll cal(ll f){
	vector<ll> cnt(m+1);
	REP(i,n){
		ll tmp=f%2;
		f/=2;
		if(tmp==1){
			REP(j,m+1){
				cnt[j]+=c[i][j];
			}
		}
	}
	FOR(i,1,m+1){
		if(cnt[i]<x){
			return INF;
		}
	}
	return cnt[0];
}
int main(){
	cin>>n;
	cin>>m;
	cin>>x;
	c.resize(n);
	REP(i,n){
		c[i].resize(m+1);
		REP(j,m+1){
			cin>>c[i][j];
		}
	}
	ll end=1<<n;
	ll min=INF;
	REP(i,end){
		//cout<<i<<endl;
		ll tmp=cal(i);
		if(min>tmp)min=tmp;
	}
	if(min==INF){
		cout<<-1<<endl;
		return 0;
	}
	cout<<min<<endl;
	return 0;
}
