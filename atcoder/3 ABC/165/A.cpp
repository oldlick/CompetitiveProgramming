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
	ll k; cin>>k;
	ll a; cin>>a;
	ll b; cin>>b;
	FOR(i,a,b+1){
		if(i%k==0){
			cout<<"OK"<<endl;
			return 0;
		}
	}
	cout<<"NG"<<endl;
	return 0;
}