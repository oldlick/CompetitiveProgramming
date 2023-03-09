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

bool hoge(string a){
	return true;
}
int main(){
	string s;
	cin>>s;
	ll end1=(s.size()-3)/2;
	REP(i,end1+1){
		if(s[i]!=s[s.size()-1-i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	ll end2=(end1+1)/2;
	REP(i,end2+1){
		if(s[i]!=s[end1-i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
