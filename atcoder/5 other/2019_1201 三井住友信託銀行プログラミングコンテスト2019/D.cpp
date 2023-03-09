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
	ll N;
	string S;
	cin>>N>>S;
	ll cnt=0;
	FOR(i,0,1000){
		ll tmp=i;
		ll old=0;
		ll j;
		for(j=0;j<3;j++){
			string c(1,(char)(tmp%10)+3*16);
			tmp/=10;
			auto it=search(S.begin()+old,S.end(),c.begin(),c.end());
			if(it==S.end())break;
			old=it-S.begin()+1;
		}
		if(j==3)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
