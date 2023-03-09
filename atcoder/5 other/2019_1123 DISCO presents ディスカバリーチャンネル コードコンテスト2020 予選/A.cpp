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
	ll X,Y;
	cin>>X>>Y;
	ll ans=0;
	if(X==3){
		ans+=100000;
	}else if(X==2){
		ans+=200000;
	}else if(X==1){
		ans+=300000;
	}
	if(Y==3){
		ans+=100000;
	}else if(Y==2){
		ans+=200000;
	}else if(Y==1){
		ans+=300000;
	}
	if(X==1 && Y==1){
		ans+=400000;
	}
	cout<<ans;
	return 0;
}
