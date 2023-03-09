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
	ll c; cin>>c;
	ll d; cin>>d;
	while(1){
		c-=b;
		if(c<=0)break;
		a-=d;
		if(a<=0)break;
	}
	if(a<=0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
