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
	ll h; cin>>h;
	ll sum=1;
	ll num=1;
	while(h>=sum){
		sum=(sum+1)*2;
		num*=2;
		cout<<h<<endl;
	}
	cout<<" "<<num-1<<endl;
	return 0;
}
