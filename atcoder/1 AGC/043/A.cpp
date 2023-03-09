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

vector<vector<ll>> map;

bool drop(ll r,ll d,ll cnt){
	if(d<0)return 0;
	if(r<0)return 0;
	if(d>=map.size())return 0;
	if(r>=map[0].size())return 0;
	if(d==map.size()-1 && r==map[0].size()-1)return 1;

	if(map[d][r]==INF){
		map[d][r]=cnt;
		ll ans=0;
		ans+=drop(r+1,d,cnt);
		ans+=drop(r-1,d,cnt);
		ans+=drop(r,d+1,cnt);
		ans+=drop(r,d-1,cnt);
		if(ans==0)return 0;
		else return 1;
	}else if(map[d][r]==-1){
		ll tmp_d=0;
		while(d-tmp_d>=0 && (map[d-tmp_d][r]==-1 || map[d-tmp_d][r]==cnt+1)){
			map[d-tmp_d][r]=cnt+1;
			ll tmp_r=0;
			while(r-tmp_r>=0 && (map[d-tmp_d][r-tmp_r]==-1 || map[d-tmp_d][r-tmp_r]==cnt+1)){
				map[d-tmp_d][r-tmp_r]=cnt+1;
				tmp_r++;
			}
			tmp_r=1;
			while(r+tmp_r<map[0].size() && (map[d-tmp_d][r+tmp_r]==-1 || map[d-tmp_d][r+tmp_r]==cnt+1)){
				map[d-tmp_d][r+tmp_r]=cnt+1;
				tmp_r++;
			}
			tmp_d++;
		}
		tmp_d=1;
		while(d+tmp_d<map.size() && (map[d+tmp_d][r]==-1 || map[d+tmp_d][r]==cnt+1)){
			map[d+tmp_d][r]=cnt+1;
			ll tmp_r=1;
			while(r-tmp_r>=0 && (map[d+tmp_d][r-tmp_r]==-1 || map[d+tmp_d][r-tmp_r]==cnt+1)){
				map[d+tmp_d][r-tmp_r]=cnt+1;
				tmp_r++;
			}
			tmp_r=1;
			while(r+tmp_r<map[0].size() && (map[d+tmp_d][r+tmp_r]==-1 || map[d+tmp_d][r+tmp_r]==cnt+1)){
				map[d+tmp_d][r+tmp_r]=cnt+1;
				tmp_r++;
			}
			tmp_d++;
		}
	}
	return 0;
}

int main(){
	ll h; cin>>h;
	ll w; cin>>w;
	vector<string> s(h);
	REP(i,h)cin>>s[i];

	map = vector<vector<ll>>(h,vector<ll>(w));
	REP(i,h){
		REP(j,w){
			if(s[i][j]=='.')map[i][j]=INF;
			else map[i][j]=-1;
		}
	}


	drop(0,0,0);



	REP(i,h){
		REP(j,w){
			if(map[i][j]==-1)cout<<"#";
			else if(map[i][j]==INF)cout<<".";
			else cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
/*
5 5
.####
##.##
#####
#####
####.

*/