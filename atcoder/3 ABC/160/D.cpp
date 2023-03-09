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

	ll a,b,c;
	a=x-1;
	b=y-x;
	c=n-y;
	if(a>c){
		ll tmp=a;
		a=c;
		c=tmp;
	}

	vector<ll> ans(n);
	FOR(i,1,n)ans[i]=n-i;

	// -
	ll minus=0;
	FOR(i,1,n){
		if(b<=i && i<=a+b){
			minus++;
		}
		if(b+c<i){
			minus--;
		}
		cout<<" "<<minus;
		ans[i]-=minus;
	}
	cout<<endl;

	//ex -
	FOR(i,2,b+1){
		if(b-i+1 < i){
			cout<<" "<<b-i+1;
			ans[i]-=b-i+1;
		}else{
			cout<<"  ";
		}
	}
	cout<<endl;

	//+
	ll plus=0;
	FOR(i,1,n){
		if(i<=a+1){
			plus++;
		}
		if(c+1<i){
			if(plus>0)plus--;
		}
		cout<<" "<<plus;
		ans[i]+=plus;
	}
	cout<<endl;
	
	//ex +
	FOR(i,2,n){
		if(b-i+1 > i){
			cout<<" "<<i;
			ans[i]+=i;
		}else{
			cout<<"  ";
		}
	}
	cout<<endl;

	FOR(i,1,n)cout<<ans[i]<<endl;
	

	return 0;
}
