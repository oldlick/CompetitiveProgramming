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
	FOR(i,1,10000){
		if((ll)(i*0.08)==a){
			if((ll)(i*0.10)==b){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
