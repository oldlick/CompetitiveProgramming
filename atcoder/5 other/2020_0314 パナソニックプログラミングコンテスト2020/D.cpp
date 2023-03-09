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

void hoge(string a,int kind,int n,int end){
	string tmp=a;
	if(n==end){
		cout<<tmp<<endl;
		return;
	}
	REP(i,kind){
		tmp[n]=i+'a';
		hoge(tmp,kind,n+1,end);
	}
	tmp[n]=kind+'a';
	hoge(tmp,kind+1,n+1,end);
	return;
}

int main(){
	ll n; cin>>n;
	string a(n,'a');
	hoge(a,1,1,n);
	return 0;
}
