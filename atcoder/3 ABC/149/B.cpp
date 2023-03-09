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
	ll a; cin>>a;
	ll b; cin>>b;
	ll k; cin>>k;
	if(a>=k){
		cout<<a-k<<" "<<b<<endl;
	}else if(a+b>=k){
		cout<<0<<" "<<a+b-k<<endl;
	}else{
		cout<<0<<" "<<0<<endl;
	}
	return 0;
}
