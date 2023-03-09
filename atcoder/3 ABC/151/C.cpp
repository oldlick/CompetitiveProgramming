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
	ll m; cin>>m;
	vector<ll> p(m);
	vector<ll> s(m);
	REP(i,m){
		string tmp;
		cin>>p[i];
		p[i]--;
		cin>>tmp;
		if(tmp=="AC"){
			s[i]=1;
		}else{
			s[i]=0;
		}
	}
	vector<ll> ch(n,0);
	ll ans0=0;
	ll ans1=0;
	REP(i,m){
		if(s[i]==1 && ch[p[i]]==0){
			ch[p[i]]=1;
			ans1++;
		}
	}
	REP(i,m){
		if(ch[p[i]]==1){
			if(s[i]==1){
				ch[p[i]]=2;
			}else{
				ans0++;
			}
		}
	}
	cout<<ans1<<" "<<ans0<<endl;
	return 0;
}
