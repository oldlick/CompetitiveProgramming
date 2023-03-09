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
	vector<ll> s(m);
	vector<ll> c(m);
	REP(i,m){
		cin>>s[i];
		s[i]--;
		cin>>c[i];
	}
	vector<ll> num(n,-1);
	REP(i,m){
		if(num[s[i]]!=c[i] && num[s[i]]!=-1){
			cout<<-1<<endl;
			return 0;
		}
		num[s[i]]=c[i];
	}
	if(num[0]==0){
		if(n==1){
			cout<<0<<endl;
			return 0;
		}else{
			cout<<-1<<endl;
			return 0;
		}
	}
	REP(i,n){
		if(num[i]==-1){
			if(i==0 && i!=n-1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<num[i];
		}
	}
	cout<<endl;
	return 0;
}
