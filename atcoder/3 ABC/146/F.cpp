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
	ll N,M;
	string S;
	cin>>N>>M>>S;
	ll now=N;
	vector<ll> ans;
	while(1){
		ll i;
		for(i=M;i>=1;i--){
			if(now-i<0)continue;
			if(S[now-i]=='0'){
				ans.push_back(i);
				now-=i;
				break;
			}
		}
		if(i==0){
			cout<<-1<<endl;
			return 0;
		}
		//cout<<now<<" ";//
		if(now==0)break;
	}
	//cout<<endl;//
	REP(i,ans.size()){
		cout<<ans[ans.size()-i-1]<<" ";
	}
	cout<<endl;
	return 0;
}
