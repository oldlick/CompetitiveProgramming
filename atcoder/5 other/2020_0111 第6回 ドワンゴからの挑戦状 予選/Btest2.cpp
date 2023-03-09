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
#define MOD (1000000000+7)

int main(){
	ll n;
	cin>>n;
	//cout << "t: "; REP(i,(signed)t.size()) cout<<t[i]<<" "; cout << endl; //----------cout----------//

	vector<vector<ll>> ans3(n,vector<ll>(n,0));
	ans3[0][0]=1;
	for(ll k=0;k<n-1;k++){
		REP(j,k+1){
			REP(i,j+1){
				ans3[i][j]*=k+2;
			}
		}
		REP(i,k+1){
			ans3[i][k+1]+=ans3[i][k]*((double)(k+1)/(k+2));
			ans3[i+1][k+1]+=ans3[i][k]*((double)1/(k+2));
		}
	}
	vector<ll> mul(n,0);
	REP(i,n){
		REP(j,n){
			mul[j]+=ans3[i][j]*(i+1);
			mul[j]%=MOD;
		}
	}
	cout << "mul: "; REP(i,(signed)mul.size()) cout<<mul[i]<<" "; cout << endl; //----------cout----------//

	return 0;
}
