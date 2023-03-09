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
	ll sum=0;
	ll num=1;
	while(h>0){
		if(h==1)h=0;
		else{
			h=h/2;
		}
		sum+=num;
		num*=2;
	}
	cout<<sum<<endl;
	return 0;
}
