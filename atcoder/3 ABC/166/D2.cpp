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
	ll x; cin>>x;
	REP(i,200){
		REP(j,200){
			if(pow(i,5)-pow(j,5)==x){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			if(pow(i,5)+pow(j,5)==x){
				cout<<i<<" "<<-j<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
