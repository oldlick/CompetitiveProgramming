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
	ll a=0;
	a=x/500;
	x-=a*500;
	ll b=0;
	b=x/5;
	cout<<a*1000+b*5<<endl;
	return 0;
}
