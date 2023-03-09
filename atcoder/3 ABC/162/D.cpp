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
	string s; cin>>s;
	vector<ll> r;
	vector<ll> g;
	vector<ll> b;
	REP(i,n){
		if(s[i]=='R')r.push_back(i);
		if(s[i]=='G')g.push_back(i);
		if(s[i]=='B')b.push_back(i);
	}
	ll ans=r.size()*g.size()*b.size();
	REP(i,r.size()){
		REP(j,g.size()){
			ll tmp;
			tmp=r[i]*2-g[j];
			if(0<=tmp && tmp<n){
				if(s[tmp]=='B'){
					ans--;
					//cout<<r[i]<<" @ "<<g[j]<<endl;
				}
			}
			tmp=g[j]*2-r[i];
			if(0<=tmp && tmp<n){
				if(s[tmp]=='B'){
					ans--;
					//cout<<r[i]<<" / "<<g[j]<<endl;
				}
			}
			if((r[i]+g[j])%2==0){
				tmp=(r[i]+g[j])/2;
				if(s[tmp]=='B'){
					ans--;
					//cout<<r[i]<<" : "<<g[j]<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
