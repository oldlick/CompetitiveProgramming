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
	FOR(i,1,10){
		if(N%i==0 && N/i<=9){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
