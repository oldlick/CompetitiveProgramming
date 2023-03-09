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
#define MOD 998244353

int main(){
	int N;
	cin>>N;
	vector<int> D(N);
	int max=0;
	REP(i,N){
		cin>>D[i];
		if(D[i]>max)max=D[i];
	}
	if(D[0]!=0){
		cout<<0;
		return 0;
	}
	vector<int> cnt(max+1,0);
	REP(i,N)cnt[D[i]]++;
	if(cnt[0]!=1){
		cout<<0;
		return 0;
	}
	ll ans=1;
	FOR(i,1,max+1){
		ll tmp=1;
		REP(j,cnt[i])tmp=(tmp*cnt[i-1])%MOD;
		ans=(ans*tmp)%MOD;
	}
	cout<<ans;
	return 0;
}