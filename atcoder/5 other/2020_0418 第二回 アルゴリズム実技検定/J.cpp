#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define REP(i,n) for(ll i=0;i<(ll)n;i++)
#define REPR(i,n) for(ll i=(ll)n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	string s;
	cin>>s;
	deque<ll> p;
	REP(i,s.size()){
		if(s[i]=='('){
			p.push_back(i);
			continue;
		}
		if(s[i]==')'){
			ll l=p.back(),r=i;
			p.pop_back();
			string p1,p2,p3;
			p1=s.substr(0,l);
			p2=s.substr(l+1,r-l-1);
			p3=s.substr(r+1,s.size()-r-1);
			string tmp=p1;
			tmp+=p2;
			reverse(p2.begin(),p2.end());
			tmp+=p2;
			tmp+=p3;
			swap(s,tmp);
			//cout<<s<<endl;
			i=l-1;
			continue;
		}
	}
	cout<<s<<endl;
	return 0;
}
