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
	string S;
	cin>>S;
	if(N%2==1){
		cout<<"No";
		return 0;
	}
	REP(i,N/2){
		if(S[i]!=S[i+N/2]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
