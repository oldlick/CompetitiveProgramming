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
	ll x; cin>>x;
	ll y; cin>>y;
	ll an; cin>>an;
	ll bn; cin>>bn;
	ll cn; cin>>cn;
	vector<ll> a(an);
	REP(i,an) cin>>a[i];
	vector<ll> b(bn);
	REP(i,bn) cin>>b[i];
	vector<ll> c(cn);
	REP(i,cn) cin>>c[i];

	vector<pair<ll,ll>> v(an+bn+cn);
	REP(i,an){
		v[i].first=a[i];
		v[i].second=0;
	}
	REP(i,bn){
		v[i+an].first=b[i];
		v[i+an].second=1;
	}
	REP(i,cn){
		v[i+an+bn].first=c[i];
		v[i+an+bn].second=2;
	}
	sort(v.begin(),v.end());

	//cout << "v: "; REP(i,(signed)v.size()) cout<<v[i].first<<" "; cout << endl; //----------cout----------//


	ll n=an+bn+cn;
	ll ans=0;
	ll X=0,Y=0,Z=0;
	ll i=0;
	while(X+Y+Z<x+y){
		if(X<x && v[n-1-i].second==0){
			X++;
			ans+=v[n-1-i].first;
			//cout<<"x "<<v[n-1-i].first<<endl;
		}else if(Y<y && v[n-1-i].second==1){
			Y++;
			ans+=v[n-1-i].first;
			//cout<<"y "<<v[n-1-i].first<<endl;
		}else if(v[n-1-i].second==2){
			Z++;
			ans+=v[n-1-i].first;
			//cout<<"z "<<v[n-1-i].first<<endl;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 2 3 2 1
3 4 5
1 1 
2
*/