#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll n; cin>>n;
	vector<tuple<double,ll,ll>> p(n,tuple<double,ll,ll>(0,0,0));
	vector<tuple<double,ll,ll>> q(n,tuple<double,ll,ll>(0,0,0));
	REP(i,n){
		ll a,b;
		cin>>a>>b;
		p[i]=tuple<double,ll,ll>((double)a/b,a,b);
		q[i]=tuple<double,ll,ll>((double)-b/a,a,b);
	}
	ll cnt=0;
	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
	double cur=0;
	
	REP(i,n){
		while(cur<n){
			double &pd=get<0>(p[i]);
			double &qd=get<0>(q[cur]);
			if(pd-qd>0.000001){
				cur++;
				continue;
			}else{
				ll &ai=get<1>(p[i]);
				ll &bi=get<2>(p[i]);
				ll &aj=get<1>(q[cur]);
				ll &bj=get<2>(q[cur]);
				if(ai*aj+bi*bj==0){
					cnt++;
				}
				break;
			}
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}
