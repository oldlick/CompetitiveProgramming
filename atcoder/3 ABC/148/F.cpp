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

void longth(vector<vector<ll>> road,vector<ll>& to_e,ll now,ll old){
	if(to_e[now]!=INF)return;
	if(old==INF)to_e[now]=0;
	else to_e[now]=to_e[old]+1;
	REP(i,road[now].size()){
		longth(road,to_e,road[now][i],now);
	}
	return;
}
int main(){
	ll n,e,s;
	cin>>n>>e>>s;
	e--;s--;
	vector<vector<ll>> road(n);
	REP(i,n-1){
		ll tmp1,tmp2;
		cin>>tmp1>>tmp2;
		road[tmp1-1].push_back(tmp2-1);
		road[tmp2-1].push_back(tmp1-1);
	}

	vector<ll> to_e(n,INF);
	longth(road,to_e,e,INF);

	cout << "to_e: ";REP(i, to_e.size()) cout<<to_e[i]<<" ";cout << endl;

	ll max=0;
	cout<<(to_e[s])<<endl;
	cout<<(to_e[s]+1)/2<<endl;
	REP(i,n){
		if(to_e[i]<(to_e[s]+1)/2){
			cout<<i<<" @"<<endl;
			vector<ll> to_i(n,INF);
			longth(road,to_i,i,INF);
			REP(j,n){
				if(max<to_e[i]+to_i[j]){
					max=to_e[i]+to_i[j];
				}
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
