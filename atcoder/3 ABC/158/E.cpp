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

ll hoge(ll p){
	ll ans=0;
	while(p!=0){
		p/=10;
		ans++;
	}
	return ans;
}

int main(){
	ll n; cin>>n;;
	ll p; cin>>p;
	string s;
	cin>>s;

	ll num=pow(10,hoge(p));
	cout<<num;
	return 0;
}
