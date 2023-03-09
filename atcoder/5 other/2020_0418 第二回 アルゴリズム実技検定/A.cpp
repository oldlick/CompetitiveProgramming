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
	string s,t;
	cin>>s>>t;
	ll b,e;
	if(s[0]=='B'){
		b=-(s[1]-'0');
	}else{
		b=s[0]-'0'-1;
	}
	if(t[0]=='B'){
		e=-(t[1]-'0');
	}else{
		e=t[0]-'0'-1;
	}
	cout<<abs(e-b)<<endl;
	return 0;
}