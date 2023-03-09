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
	ll m; cin>>m;
	vector<vector<ll>> l(n);
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		a--;b--;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	deque<pair<ll,ll>> q;
	vector<ll> ans(n,-2);
	q.push_back(pair<ll,ll>(0,0));
	while(q.size()!=0){
		ll now=q.front().first;
		ll old=q.front().second;
		q.pop_front();

		ans[now]=old;
		
		//cout<<now<<":";
		//cout << "q: "; REP(i,(signed)q.size()) cout<<q[i].first<<" "; cout << endl; //----------cout----------//


		for(auto &i:l[now]){
			if(i==old)continue;
			if(ans[i]!=-2)continue;
			q.push_back(pair<ll,ll> (i,now));
			ans[i]=-1;
		}
	}
	std::cout<<"Yes"<<endl;
	FOR(i,1,n){
		std::cout<<ans[i]+1<<endl;
	}
	return 0;
}
/*
10 10
1 2
2 4
4 7
2 5
5 8
5 9
1 3
3 6
6 10
3 5
*/