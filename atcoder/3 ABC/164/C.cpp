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
	vector<string> s(n);
	REP(i,n) cin>>s[i];
	sort(s.begin(),s.end());
	ll ans=0;
	REP(i,n){
		if(i==0){
			ans++;
		}else{
			if(s[i]!=s[i-1]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
