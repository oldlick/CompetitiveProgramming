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
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	auto start=a.begin();
	ll fnum=0;
	FOR(i,1,n+1){
		auto it=find(start,a.end(),i);
		if(it==a.end())break;
		else{
			fnum++;
			start=it;
		}
	}
	if(fnum==0)cout<<-1<<endl;
	else cout<<n-fnum<<endl;
	return 0;
}
