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
	ll N,K;
	cin>>N>>K;
	vector<ll> A(N);
	REP(i,N){
		ll tmp;
		cin>>tmp;
		A[i]=tmp%K;
	}
	ll ans=0;
	REP(i,N){
		FOR(j,i,N){
			ll sum=0;
			FOR(k,i,j+1){
				sum+=A[k];
			}
			if(sum%K==(j-i+1)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
