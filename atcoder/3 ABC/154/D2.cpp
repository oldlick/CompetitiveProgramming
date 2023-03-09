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
	ll k; cin>>k;
	vector<double> p(n);
	REP(i,n) cin>>p[i];


	REP(i,n) p[i]=(p[i]+1)/2;
	double max=0;

	REP(j,n-k+1){
		double tmp=0;
		REP(i,k){
			tmp+=p[j+i];
		}
		if(tmp>max)max=tmp;
	}
	cout<<max<<endl;
	return 0;
}
