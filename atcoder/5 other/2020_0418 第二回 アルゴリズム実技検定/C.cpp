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
	vector<string> s(n);
	REP(i,n){
		cin>>s[i];
	}
	for(int i=n-2;i>=0;i--){
		FOR(j,n-1-i,i+n){
			if(s[i][j]=='#'){
				if(s[i+1][j-1]=='X'){
					s[i][j]='X';
				}
				if(s[i+1][j]=='X'){
					s[i][j]='X';
				}
				if(s[i+1][j+1]=='X'){
					s[i][j]='X';
				}
			}
		}
	}
	REP(i,n){
		cout<<s[i]<<endl;
	}
	return 0;
}
