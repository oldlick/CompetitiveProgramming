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
	ll N;
	cin>>N;
	vector<ll> A(N);
	REP(i,N){
		cin>>A[i];
	}
	ll lsum=0,rsum=0;
	ll l=0,r=N-1;
	while(l<=r){
		if(lsum<rsum){
			lsum+=A[l];
			l++;
		}else{
			rsum+=A[r];
			r--;
		}
	}
	cout<<(lsum-rsum>0 ? lsum-rsum : rsum-lsum)<<endl;
	return 0;
}
