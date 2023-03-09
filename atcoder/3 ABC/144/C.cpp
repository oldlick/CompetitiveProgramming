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
	ll end=sqrt(N);
	
	for(int i=end;i>=1;i--){
		if(N%i==0){
			cout<<(i-1)+(N/i-1);
			return 0;
		}
	}
	return 0;
}
