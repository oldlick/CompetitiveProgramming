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
	ll A,B;
	cin>>A>>B;
	if(A<10 && B<10){
		cout<<A*B;
	}else{
		cout<<"-1";
	}
	return 0;
}
