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
	ll m; cin>>m;
	vector<pair<ll,ll>> d(n+2*m);
	REP(i,n){
		cin>>d[i].first;
		cin>>d[i].second;
	}
	REP(i,m){
		cin>>d[i*2].first;
		d[i*2].second=-2;
		cin>>d[i*2+1].first;
		d[i*2+1].second=2;
	}
	sort(d.begin(),d.end());


	vector<pair<ll,ll>> c(n);
	ll num=0;
	ll col=-1;
	REP(i,n+m*2){
		if(d[i].second==-2){
			num++;
		}
		if(d[i].second==2){
			num--;
			col=-1;
		}
		if(d[i].second==0){
			if(col==1){
				goto NO;
			}else{
				col=0;
			}
		}
		if(d[i].second==1){
			if(num==0) goto NO;
			if(col==0){
				goto NO;
			}else{
				col=1;
			}
		}
	}
	
	return 0;
	NO:
	cout<<-1<<endl;
	return 0;
}
