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

void map(vector<vector<ll>> s,vector<vector<ll>>& l,ll d,ll r,ll n){
	l[d][r]=n;
	n++;
	ll nd,nr;
	nd=d+1;nr=r+0;
	if(s[nd][nr]==0 && l[nd][nr]>n)map(s,l,nd,nr,n);
	nd=d-1;nr=r+0;
	if(s[nd][nr]==0 && l[nd][nr]>n)map(s,l,nd,nr,n);
	nd=d+0;nr=r+1;
	if(s[nd][nr]==0 && l[nd][nr]>n)map(s,l,nd,nr,n);
	nd=d+0;nr=r-1;
	if(s[nd][nr]==0 && l[nd][nr]>n)map(s,l,nd,nr,n);
}

int main(){
	ll h; cin>>h;
	ll w; cin>>w;
	h+=2;w+=2;
	vector<vector<ll>> s(h,vector<ll>(w,1));
	ll d,r;
	FOR(i,1,h-1){
		FOR(j,1,w-1){
			char c;
			cin>>c;
			if(c=='#'){
				s[i][j]=1;
			}else{
				s[i][j]=0;
				d=i;r=j;
			}
		}
	}
	
	//cout<<u<<" "<<r<<endl;
	vector<vector<ll>> l(h,vector<ll>(w,INF));
	map(s,l,d,r,0);
	FOR(i,1,h-1){
		FOR(j,1,w-1){
			if(l[i][j]!=INF && l[d][r]<l[i][j]){
				d=i;
				r=j;
			}
		}
	}
	l=vector<vector<ll>>(h,vector<ll>(w,INF));
	map(s,l,d,r,0);
	FOR(i,1,h-1){
		FOR(j,1,w-1){
			if(l[i][j]!=INF && l[d][r]<l[i][j]){
				d=i;
				r=j;
			}
		}
	}
	cout<<l[d][r]<<endl;
	return 0;
}
