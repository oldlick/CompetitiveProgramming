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
	string s;
	cin>>s;
	vector<ll>n(s.size());
	ll lsum=0,rsum=0;
	REP(i,s.size()){
		n[i]=s[s.size()-i-1]-'0';
		lsum+=n[i];
	}
	vector<ll>p(s.size());

	REP(i,n.size()){
		p[i]+=n[i];
		if(p[i]>5){
			p[i]=0;
			p[i+1]++;
		}
	}
	ll ans=0;
	REP(i,n.size()){
		ans+=p[i];
		if(p[i]>n[i]){
			ans+=p[i]-n[i];
		}else{
			ans+=10-n[i];
		}
		p[i+1]--;
	}
	cout<<ans<<endl;

	return 0;
}
