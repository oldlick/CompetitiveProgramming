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
	ll N,T;
	cin>>N>>T;
	ll min=10000;
	REP(i,N){
		ll c,t;
		cin>>c>>t;
		if(t<=T){
			if(min>c)min=c;
		}
	}
	if(min==10000){
		cout<<"TLE"<<endl;
	}else{
		cout<<min<<endl;
	}
	return 0;
}
