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
	ll an; cin>>an;
	ll bn; cin>>bn;
	ll m; cin>>m;
	vector<ll> a(an);
	REP(i,an) cin>>a[i];
	vector<ll> b(bn);
	REP(i,bn) cin>>b[i];
	vector<ll> x(m);
	vector<ll> y(m);
	vector<ll> c(m);
	REP(i,m){
		cin>>x[i];
		cin>>y[i];
		cin>>c[i];
		x[i]--;
		y[i]--;
	}

	ll amin=INF;
	ll bmin=INF;
	REP(i,an){
		if(amin>a[i])amin=a[i];
	}
	REP(i,bn){
		if(bmin>b[i])bmin=b[i];
	}
	ll min=amin+bmin;
	REP(i,m){
		ll tmp=a[x[i]]+b[y[i]]-c[i];
		if(min>tmp)min=tmp;
	}
	cout<<min<<endl;

	return 0;
}
