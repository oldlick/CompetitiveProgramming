#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define REP(i,n) for(ll i=0;i<(ll)n;i++)
#define REPR(i,n) for(ll i=(ll)n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll n; cin>>n;
	string s;
	cin>>s;
	vector<ll> c(n);
	REP(i,n) cin>>c[i];
	vector<ll> d(n);
	REP(i,n) cin>>d[i];
	vector<vector<ll>> dp(n+1,vector<ll>(n,INF));
	//dp[i][j]:=i文字目まで考慮してj個の括弧が開いているときのコスト最小値
	dp[0][0]=0;
	REP(i,n){
		//cout << "dp["<<i<<"]: "; REP(j,(signed)dp[i].size()) cout<<dp[i][j]<<" "; cout << endl; //----------cout----------//	
		REP(j,n){
			if(s[i]==')'){
				//nothing
				if(j-1>=0){
					dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]);
				}
				//reverse
				if(j+1<n){
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+c[i]);
				}
			}else{
				//nothing
				if(j+1<n){
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
				}
				//reverse
				if(j-1>=0){
					dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+c[i]);
				}
			}
			//delete
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+d[i]);
		}
	}
	//cout << "dp["<<n<<"]: "; REP(j,(signed)dp[n].size()) cout<<dp[n][j]<<" "; cout << endl; //----------cout----------//
	cout<<dp[n][0]<<endl;
	return 0;
}
