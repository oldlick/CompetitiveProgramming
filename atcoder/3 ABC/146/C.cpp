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

ll c(ll n){
	ll ans=0;
	while(n!=0){
		n/=10;
		ans++;
	}
	return ans;
}
int main(){
	ll A,B,X;
	cin>>A>>B>>X;
	ll l=1,r=1000000000;
	ll tmp;
	while(l<r){
		tmp=((l+r)/2)+1;
		//cout<<l<<" "<<tmp<<" "<<r<<endl;
		if(A*tmp+B*c(tmp)<=X){
			l=tmp;
		}else{
			r=tmp-1;
		}
	}
	if(A*l+B*c(l)<=X){
		cout<<l<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}
