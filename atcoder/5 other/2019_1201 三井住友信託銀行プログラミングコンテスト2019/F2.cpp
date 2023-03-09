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
	ll a[3],b[3],t[2];
	cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
	REP(i,2){
		a[i]=a[i]*t[i];
		b[i]=b[i]*t[i];
	}
	a[2]=a[0]+a[1];
	b[2]=b[0]+b[1];
	if(a[2]==b[2]){
		cout<<"infinity"<<endl;
		return 0;
	}
	vector<ll> cnt(a[2]+b[2],0);
	
	cout<<cnt<<endl;
	return 0;
}
