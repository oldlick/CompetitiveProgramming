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

ll Max(ll a,ll b,ll c){
	ll max=a;
	if(max<b)max=b;
	if(max<c)max=c;
	return max;
}
class SOLVE{
	vector<vector<ll>> q;
	vector<ll> p;
	public:
	SOLVE(vector<ll> tmp){
		REP(i,3){
			p.push_back(tmp[i]);
		}
	}
	void in(ll t){
		ll i=q.size();
		q.push_back(vector<ll>(3,-INF));
		REP(j,3){
			if((t+2)%3==j){
				if(i==0){
					q[i][j]=p[j];
				}else{
					REP(k,3){
						if(k!=j && q[i][j]<q[i-1][k]+p[j])q[i][j]=q[i-1][k]+p[j];
					}
				}
			}else{
				if(i==0){
					q[i][j]=0;
				}else{
					REP(k,3){
						if(k!=j && q[i][j]<q[i-1][k])q[i][j]=q[i-1][k];
					}
				}
			}
		}
		//cout << "q: "; REP(j,(signed)q[i].size()) cout<<q[i][j]<<" "; cout << endl; //----------cout----------//
	}
	ll out(){
		ll n=q.size();
		return Max(q[n-1][0],q[n-1][1],q[n-1][2]);
	}
};

int main(){
	ll n; cin>>n;
	ll k; cin>>k;
	vector<ll> p(3);
	REP(i,3) cin>>p[i];
	string S; cin>>S;
	vector<ll> t(n);
	REP(i,n){
		if(S[i]=='r')t[i]=0;
		if(S[i]=='s')t[i]=1;
		if(S[i]=='p')t[i]=2;
	}
	vector<SOLVE> s(k,p);
	REP(i,n){
		s[i%k].in(t[i]);
	}
	ll ans=0;
	REP(i,k){
		ans+=s[i].out();
	}
	cout<<ans<<endl;
	return 0;
}
