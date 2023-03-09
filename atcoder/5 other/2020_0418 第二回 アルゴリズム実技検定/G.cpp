#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll n; cin>>n;
	deque<pair<char,ll>> s;
	REP(i,n){
		ll t;cin>>t;
		if(t==1){
			char c;cin>>c;
			ll x;cin>>x;
			s.push_back(pair<char,ll>(c,x));
			/*
			cout<<"//";
			REP(j,s.size()){
				REP(k,s[j].second){
					cout<<s[j].first;
				}
			}
			cout<<endl;*/
		}else{
			ll x;cin>>x;
			map<char,ll> cnt;
			while(x>0){
				if(s.size()==0){
					break;
				}
				if(x>=s[0].second){
					x-=s[0].second;
					cnt[s[0].first]+=s[0].second;
					s.pop_front();
				}else{
					s[0].second-=x;
					cnt[s[0].first]+=x;
					x=0;
				}
			}
			ll ans=0;
			REP(j,26){
				ans+=pow(cnt[j+'a'],2);
			}
			//cout<<"//";
			cout<<ans<<endl;
		}
	}
	return 0;
}
