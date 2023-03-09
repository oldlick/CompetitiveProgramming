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
	ll k; cin>>k;
	ll m; cin>>m;
	ll sum=0;
	ll tmp;
	REP(i,n-1){
		cin>>tmp;
		sum+=tmp;
	}
	m*=n;
	REP(i,k+1){
		if(sum+i>=m){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
