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

void swap(ll &a, ll &b){
	ll tmp=a;
	a=b;
	b=tmp;
}

int main(){
	ll n; cin>>n;
	ll d; cin>>d;
	ll a; cin>>a;
	vector<pair<ll,ll>> xh(n);
	vector<ll> next(n);
	REP(i,n) {
		cin>>xh[i].first;
		cin>>xh[i].second;
		next[i]=(i+1)%n;
	}
	sort(xh.begin(),xh.end());
	ll sum=0;
	ll i=0;
	do{
		if(xh[i].second<=0)continue;
		ll tmp=xh[i].second/a+(xh[i].second%a!=0);
		ll at=tmp*a;
		ll j=i+1;
		do{
			if(xh[j].first>xh[i].first+2*d)break;
			if(xh[j].second<=at){
				next[i]=next[next[i]];
			}else{
				xh[j].second-=at;
				j=next[j];
			}
		}while(j!=0);
		sum+=tmp;
		i=next[i];
	}while(i!=0);
	cout<<sum<<endl;
	return 0;
}