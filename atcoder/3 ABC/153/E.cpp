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
	ll n; cin>>n;
	vector<ll> a(n);
	vector<ll> b(n);
	REP(i,n) {
		cin>>a[i];
		cin>>b[i];
	}
	vector<ll> m(h+1,INF);
	m[0]=0;
	FOR(i,0,h){
		REP(j,n){
			FOR(k,i+1,i+a[j]+1){
				if(k>h)break;
				m[k]=min(m[k],m[i]+b[j]);
			}
		}
		//cout << "m: "; REP(i,(signed)m.size()) cout<<m[i]<<" "; cout << endl; //----------cout----------//
	}
	cout<<m[h]<<endl;
	return 0;
}