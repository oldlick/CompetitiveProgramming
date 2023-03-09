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
	string s;
	cin>>s;
	ll q; cin>>q;

	deque<char> ans;
	ll inv=0;
	REP(i,s.size()){
		ans.push_back(s[i]);
	}


	REP(i,q){
		char tmp;
		cin>>tmp;
		if(tmp=='1')inv++;
		if(tmp=='2'){
			cin>>tmp;
			tmp-='0';
			if((tmp+inv)%2==1){
				cin>>tmp;
				ans.push_front(tmp);
			}else{
				cin>>tmp;
				ans.push_back(tmp);
			}
		}
	}
	if(inv%2==0){
		REP(i,ans.size()){
			cout<<ans[i];
		}
	}else{
		REP(i,ans.size()){
			cout<<ans[ans.size()-i-1];
		}
	}
	cout<<endl;
	return 0;
}
