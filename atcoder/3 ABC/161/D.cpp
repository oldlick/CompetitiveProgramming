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

bool ch(ll n){
	ll n2=n;
	ll old=-1;
	while(n2>0){
		ll tmp=n2%10;
		if(old!=-1 && abs(tmp-old)>1){

			false;
		}
		old=tmp;
		n2/=10;
	}
	return true;
}
int main(){
	ll n; cin>>n;
	ll i=0;
	unsigned long long tmp=0;
	while(1){
		tmp++;
		if(ch(tmp)==true)i++;
		else{
			tmp;
		}
		if(i==n)break;
	}
	cout<<tmp<<endl;
	return 0;
}
