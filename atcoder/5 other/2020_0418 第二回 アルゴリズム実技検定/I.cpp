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

int main(){
	ll n; cin>>n;
	deque<pair<ll,ll>> a;
	REP(i,pow(2,n)){
		ll tmp;
		cin>>tmp;
		a.push_back(pair<ll,ll>(i,tmp));
	}
	vector<ll> ans(pow(2,n));
	for(int i=n;i>0;i--){
		REP(j,pow(2,i-1)){
			//cout<<i<<" "<<j<<endl;
			//cout << "a: "; REP(i,(signed)a.size()) cout<<a[i].first<<" "; cout << endl; //----------cout----------//
			if(a[0].second>a[1].second){
				a.push_back(a[0]);
			}else{
				a.push_back(a[1]);
			}
			ans[a[1].first]=n-i+1;
			ans[a[0].first]=n-i+1;
			a.pop_front();
			a.pop_front();
		}
	}
	REP(i,pow(2,n)){
		cout<<ans[i]<<endl;
	}
	return 0;
}
