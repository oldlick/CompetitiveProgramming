#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	string s;
	cin>>s;
	map<char,ll> ans;
	REP(i,s.size()){
		ans[s[i]]++;
	}
	char max='a';
	REP(i,3){
		if(ans[max]<ans[i+'a'])max=i+'a';
	}
	cout<<max<<endl;
	return 0;
}
