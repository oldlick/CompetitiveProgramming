#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll M;
	cin>>M;
	ll ans=0;
	
	ll sum=0,n=0;
	REP(i,M){
		ll c,d;
		cin>>d>>c;
		sum+=d*c;
		if(sum>=10){
			ans++;
			sum-=9;
		}
		n+=c;
	}
	ans+=n-1;
	cout<<ans<<endl;
	return 0;
}
