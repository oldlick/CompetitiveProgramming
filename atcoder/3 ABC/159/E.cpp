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
	ll h; cin>>h;
	ll w; cin>>w;
	ll k; cin>>k;
	vector<vector<ll>> map(h,vector<ll>(w));
	REP(i,h){
		string s;
		cin>>s;
		REP(j,w){
			map[i][j]=s[j]-'0';
		}
	}
	
	vector<vector<ll>> num(h,vector<ll>(w));
	REP(i,h){
		ll tmp=0;
		REP(j,w){
			if(map[i][j]==1)tmp++;
			if(i==0)num[i][j]=tmp;
			else num[i][j]=num[i-1][j]+tmp;
		}
	}

	cout<<endl;
	REP(i,h){
		REP(j,w){
			cout<<num[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}