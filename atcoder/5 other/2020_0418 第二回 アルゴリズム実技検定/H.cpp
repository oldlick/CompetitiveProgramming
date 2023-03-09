#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18
ll d(pair<ll,ll> a,pair<ll,ll> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
	ll n; cin>>n;
	ll m; cin>>m;
	map<ll,vector<pair<ll,ll>>> a;
	REP(i,n){
		string s;cin>>s;
		REP(j,m){
			ll tmp=0;
			if(s[j]=='S')tmp=0;
			else if(s[j]=='G')tmp=10;
			else tmp=s[j]-'0';
			a[tmp].push_back(pair<ll,ll>(i,j));
		}
	}
	FOR(i,1,10){
		if(a.count(i)==0){
			cout<<-1<<endl;
			return 0;
		}
	}/*
	REP(i,11){
		cout<<i<<":"<<endl;
		REP(j,a[i].size()){
			cout<<a[i][j].first<<" "<<a[i][j].second<<endl;
		}
	}*/
	vector<pair<pair<ll,ll>,ll>> cur(1,pair<pair<ll,ll>,ll>(a[0][0],0));
	REP(i,10){
		vector<pair<pair<ll,ll>,ll>> next;
		REP(j,a[i+1].size()){
			next.push_back(pair<pair<ll,ll>,ll>(a[i+1][j],INF));
			REP(k,a[i].size()){
				ll tmp=cur[k].second+d(cur[k].first,next[j].first);
				next[j].second=min(next[j].second,tmp);
			}
		}
		swap(cur,next);
	}
	cout<<cur[0].second<<endl;
	return 0;
}
