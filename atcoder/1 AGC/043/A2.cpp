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

vector<vector<ll>> memo;
vector<vector<ll>> map;

void DFS(ll d,ll r,ll oldmap,ll cnt){
	if(d<0)return;
	if(r<0)return;
	if(d>=memo.size())return;
	if(r>=memo[0].size())return;
	
	if(oldmap!=map[d][r])cnt++;
	if(memo[d][r]<=cnt)return;
	else memo[d][r]=cnt;
	
	DFS(d+1,r,map[d][r],cnt);
	DFS(d,r+1,map[d][r],cnt);

	return;
}

int main(){
	ll h; cin>>h;
	ll w; cin>>w;
	vector<string> s(h);
	REP(i,h)cin>>s[i];

	memo = vector<vector<ll>>(h,vector<ll>(w,INF));
	map = vector<vector<ll>>(h,vector<ll>(w));
	REP(i,h){
		REP(j,w){
			if(s[i][j]=='.')map[i][j]=0;
			else map[i][j]=1;
		}
	}

	DFS(0,0,0,0);
	/*
	cout<<endl;
	REP(i,h){
		REP(j,w){
			cout<<memo[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	*/

	cout<<(memo[h-1][w-1]+1)/2<<endl;
	return 0;
}
/*
5 5
####.
###.#
##.##
#.###
.####

5 5
##..#
#..#.
#####
.#..#
#..##

5 5
.#...
.#.#.
.#.#.
.#.#.
...#.

*/