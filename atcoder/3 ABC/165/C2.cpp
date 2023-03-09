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
bool next(vector<ll> &a,ll m){
	REPR(i,a.size()){
		if(a[i]==m)continue;
		a[i]++;
		FOR(j,i+1,a.size())a[j]=a[i];
		return true;
	}
	return false;
}

int main(){
	ll n; cin>>n;
	ll m; cin>>m;
	vector<ll> a(n,1);
	ll ans=0;
	do{
		//cout << "a: "; REP(i,(signed)a.size()) cout<<a[i]<<" "; cout << endl; //----------cout----------//

		ans++;
	}while(next(a,m));
	cout<<ans<<endl;
	return 0;
}
