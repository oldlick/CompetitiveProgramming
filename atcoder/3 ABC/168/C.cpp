#define _USE_MATH_DEFINES
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
	ll a; cin>>a;
	ll b; cin>>b;
	long double h; cin>>h;
	long double m; cin>>m;
	h=h/12*2*M_PI;
	h+=m/(60*12)*2*M_PI;
	m=m/60*2*M_PI;
	long double ans;
	ans=a*a+b*b-2*a*b*cosl(h-m);
	printf("%.10llf\n",sqrtl(ans));
	return 0;
}
