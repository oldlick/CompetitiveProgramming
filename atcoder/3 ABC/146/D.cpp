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
void solve(vector<vector<pair<ll,ll>>> &node,ll num,ll used,vector<ll> &clr){
	ll color=1;
	REP(i,node[num].size()){
		if(clr[node[num][i].second]==0){
			if(color==used)color++;
			clr[node[num][i].second]=color;
			solve(node,node[num][i].first,color,clr);
			color++;
		}
	}
}
int main(){
	ll N;
	cin>>N;
	vector<vector<pair<ll,ll>>> node(N);
	REP(i,N-1){
		ll tmp1,tmp2;
		cin>>tmp1>>tmp2;
		tmp1--;tmp2--;
		node[tmp1].push_back(pair<ll,ll>(tmp2,i));
		node[tmp2].push_back(pair<ll,ll>(tmp1,i));
	}
	int max=0;
	REP(i,N){
		if(max<node[i].size()) max=node[i].size();
	}
	cout<<max<<endl;
	vector<ll> clr(N-1);
	solve(node,0,0,clr);
	REP(i,N-1){
		cout<<clr[i]<<endl;
	}
	return 0;
}
