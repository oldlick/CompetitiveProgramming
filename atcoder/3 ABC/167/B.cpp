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
	ll c; cin>>c;
	ll k; cin>>k;
	if(k<=a){
		cout<<k<<endl;
		return 0;
	}else if(k<=a+b){
		cout<<a<<endl;
		return 0;
	}else{
		cout<<a-(k-a-b)<<endl;
		return 0;
	}
	return 0;
}
