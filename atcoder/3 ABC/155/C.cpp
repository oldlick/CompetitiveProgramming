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
	vector<pair<ll,string>> l;
	REP(i,n){
		if(i==0){
			l.push_back(make_pair(1,s[i]));
		}else{
			if(l[l.size()-1].second==s[i])l[l.size()-1].first++;
			else l.push_back(make_pair(1,s[i]));
		}
	}
	sort(l.begin(),l.end());
	ll max=l[l.size()-1].first;
	REP(i,l.size()){
		if(l[i].first==max)cout<<l[i].second<<endl;
	}
	return 0;
}
