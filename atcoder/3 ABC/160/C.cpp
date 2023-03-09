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
	ll k; cin>>k;
	ll n; cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];

	vector<ll> l(n);
	REP(i,n-1){
		l[i]=a[i+1]-a[i];
	}
	l[n-1]=k-(a[n-1]-a[0]);

	//cout << "l: "; REP(i,(signed)l.size()) cout<<l[i]<<" "; cout << endl; //----------cout----------//


	sort(l.begin(),l.end());
	cout<<k-l[n-1]<<endl;
	
	return 0;
}
