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
	string S; cin>>S;
	ll q; cin>>q;
	vector<ll> s(n);
	REP(i,n){
		s[i]=S[i]-'a';
	}
	vector<vector<int>> num(26,vector<int>(n,0));
	REP(i,26){
		REP(j,n){
			if(j!=0)num[i][j]+=num[i][j-1];
			if(s[j]==i)num[i][j]++;
		}
	}
	REP(i,(signed)num.size()){
		REP(j,(signed)num[i].size()){
			cout<<num[i][j]<<" "; //----------cout----------//
		}
		cout << endl;
	}

	REP(i,q){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			c-='a';
			int old=s[b];
			s[b]=c;

			num[old];
		}else{

		}
	}
	return 0;
}
