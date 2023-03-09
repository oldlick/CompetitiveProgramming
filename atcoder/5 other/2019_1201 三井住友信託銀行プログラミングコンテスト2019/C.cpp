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
	ll X;
	cin>>X;
	ll div=X/100;
	if(div==0){
		cout<<"0"<<endl;
		return 0;
	}
	ll mod=X%100;
	ll num;
	if((double)mod/5==mod/5)num=mod/5;
	else num=mod/5+1;
	if(div>=num){
		cout<<"1"<<endl;
	}else{
		cout<<"0"<<endl;
	}
	return 0;
}
