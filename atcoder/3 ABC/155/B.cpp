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
	REP(i,n) cin>>a[i];
	REP(i,n){
		if(a[i]%2==0){
			if(a[i]%3!=0 && a[i]%5!=0){
				cout<<"DENIED"<<endl;
				return 0;
			}
		}
	}
	cout<<"APPROVED"<<endl;
	return 0;
}
