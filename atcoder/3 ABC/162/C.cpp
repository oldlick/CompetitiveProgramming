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
ll gcd(ll a,ll b){
	ll r=0;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main(){
	ll k; cin>>k;
	ll memo[201][201]={0};
	FOR(i,1,201){
		FOR(j,1,201){
			memo[i][j]=gcd(i,j);
		}
	}
	ll sum=0;
	FOR(i,1,k+1){
		FOR(j,1,k+1){
			FOR(l,1,k+1){
				sum+=memo[i][memo[j][l]];
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
