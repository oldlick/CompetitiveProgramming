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
	ll q; cin>>q;
	vector<ll> a(q);
	vector<ll> b(q);
	vector<ll> c(q);
	vector<ll> d(q);
	REP(i,q){
		cin>>a[i];a[i]--;
		cin>>b[i];b[i]--;
		cin>>c[i];
		cin>>d[i];
	}

	vector<ll> A(n,1);
	ll maxans=0;
	do{
		//cout << "A: "; REP(i,(signed)A.size()) cout<<A[i]<<" "; cout << endl; //----------cout----------//

		ll ans=0;
		REP(i,q){
			if(A[b[i]]-A[a[i]]==c[i])ans+=d[i];
		}
		//cout<<ans<<endl;
		if(ans>maxans)maxans=ans;
	}while(next(A,m));
	cout<<maxans<<endl;
	return 0;
}
