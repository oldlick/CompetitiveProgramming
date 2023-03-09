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

ll lcm(ll a,ll b){
	ll a_=a,b_=b;
	ll r=0;
	do{
		r=a%b;
		a=b;
		b=r;
	} while (r!=0);
	return a_/a*b_;
}
int main(){
	ll a; cin>>a;
	ll b; cin>>b;
	ll n; cin>>n;
	if(a*n>=(b-1)*a){
		cout<<((b-1)*a)/b<<endl;
	}else{
		cout<<(a*n)/b<<endl;
	}
	return 0;
}
