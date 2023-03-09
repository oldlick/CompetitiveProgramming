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
	n%=10;
	if(n==3){
		cout<<"bon"<<endl;
	}else if(n==2 || n==4 || n==5 || n==7 || n==9 ){
		cout<<"hon"<<endl;
	}else{
		cout<<"pon"<<endl;
	}
	return 0;
}