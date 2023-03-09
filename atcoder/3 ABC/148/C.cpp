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
ll gcd(ll a,ll b){
	while(b!=0){
		ll r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	ll a,b;
	cin>>a>>b;
	cout<<a/gcd(a,b)*b<<endl;
	return 0;
}
