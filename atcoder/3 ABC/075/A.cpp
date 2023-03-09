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
	vector<ll> d(3);
	cin>>d[0]>>d[1]>>d[2];
	sort(d.begin(),d.end());
	if(d[1]!=d[0]){
		cout<<d[0]<<endl;
	}else{
		cout<<d[2]<<endl;
	}
	return 0;
}
