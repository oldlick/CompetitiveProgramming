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
	ll n; cin>>n;
	vector<ll> a(n);
	REP(i,n){
		cin>>a[i];
		a[i]--;
	}
	REP(i,n){
		int x=i,cnt=0;
		do{
			x=a[x];
			cnt++;
		}while(x!=i);
		cout<<cnt<<' ';
	}
	cout<<endl;
	return 0;
}
