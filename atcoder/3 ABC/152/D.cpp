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

ll hoge(ll n){
	while(n/10!=0){
		n/=10;
	}
	return n;
}

int main(){
	ll n; cin>>n;
	int c[10][10]={0};
	FOR(i,1,n+1){
		c[i%10][hoge(i)]++;
	}
	ll ans=0;
	REP(i,10){
		REP(j,10){
			ans+=c[i][j]*c[j][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
