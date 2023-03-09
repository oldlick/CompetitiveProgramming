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
	ll N;
	cin>>N;
	vector<vector<ll>> x(N,vector<ll>(N,-1));
	REP(i,N){
		ll tmp;
		cin>>tmp;
		REP(j,tmp){
			ll a,b;
			cin>>a>>b;
			x[i][a-1]=b;
		}
	}
	ll end=pow(2,N);
	ll ans=0;
	ll tmp=0;
	REP(think,end){
		REP(i,N){
			if(((think>>i)&1)==1){
				REP(j,N){
					if(x[i][j]!=-1 && x[i][j]!=((think>>j)&1)){
						goto Next;
					}
				}
			}
		}
		tmp=0;
		REP(i,N){
			//cout<<((think>>i)&1)<<" ";//
			if(((think>>i)&1)==1)tmp++;
		}
		//cout<<tmp<<endl;
		if(ans<tmp){
			ans=tmp;
		}
		Next:;
	}
	cout<<ans<<endl;
	return 0;
}
