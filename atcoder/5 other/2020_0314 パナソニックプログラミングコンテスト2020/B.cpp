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
	ll w; cin>>w;
	ll ans=0;
	if(h==1 || w==1){
		cout<<1<<endl;
		return 0;
	}
	if(h%2!=0 && w%2!=0){
		h--;
		ans=h/2;
		ans*=w;
		w--;
		ans+=w/2;
		ans++;
	}else if(h%2==0){
		ans=h/2;
		ans*=w;
	}else{
		ans=w/2;
		ans*=h;
	}
	cout<<ans<<endl;
	return 0;
}
