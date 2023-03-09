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
	ll n;
	cin>>n;
	vector<vector<ll>> ans(n,vector<ll>(n,0));
	vector<ll> x(n);
	REP(i,n)x[i]=i;
	do{
		cout << "x: "; REP(i,(signed)x.size()) cout<<x[i]<<" "; cout << endl; //----------cout----------//
		vector<ll> cnt(n,0);
		vector<ll> ch(n,0);
		REP(i,n){
			int now=x[i];
			ch[now]=1;
			while(ch[now]==1){
				cnt[now]++;
				now++;
			}
		}
		REP(i,n){
			ans[cnt[i]-1][i]++;
		}
		cout << "cnt: "; REP(i,(signed)cnt.size()) cout<<cnt[i]<<" "; cout << endl; //----------cout----------//
	}while(next_permutation(x.begin(), x.end()));
	
	REP(j,n){
		cout << "ans[j]: "; REP(i,(signed)ans[j].size()) cout<<ans[j][i]<<" "; cout << endl; //----------cout----------//
	}
	vector<vector<ll>> ans2(n,vector<ll>(n,0));
	ans2[0][0]=1;
	REP(i,n){
		ans2[0][0]*=(i+1);
	}
	REP(j,n-1){
		REP(i,n-1){
			ans2[i][j+1]+=ans2[i][j]*((double)(j+1)/(j+2));
			ans2[i+1][j+1]+=ans2[i][j]*((double)1/(j+2));
		}
	}
	REP(j,n){
		cout << "ans2[j]: "; REP(i,(signed)ans2[j].size()) cout<<ans2[j][i]<<" "; cout << endl; //----------cout----------//
	}
	REP(j,n){
		REP(i,(signed)ans2[j].size()){
			if(ans[i][j]!=ans2[i][j]){
				cout<<"no"<<endl;
			}
		}
	}
	cout<<"end"<<endl;
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
	REP(j,n){
		cout << "ans3[j]: "; REP(i,(signed)ans3[j].size()) cout<<ans3[j][i]<<" "; cout << endl; //----------cout----------//
	}
	REP(j,n){
		REP(i,(signed)ans3[j].size()){
			if(ans[i][j]!=ans3[i][j]){
				cout<<"no"<<endl;
				break;
			}
		}
	}
	cout<<"end"<<endl;
	return 0;
}
