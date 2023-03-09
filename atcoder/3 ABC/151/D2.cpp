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

ll map(vector<vector<ll>>& s,vector<vector<ll>>& l,ll u,ll r){
	ll n=l[u][r];
	ll f=0;
	n++;
	FOR(i,-1,2){
		FOR(j,-1,2){
			if(i!=0 && j!=0)continue;
			if(s[u+i][r+j]==0 && l[u+i][r+j]>n){
				l[u+i][r+j]=n;
				f=1;
			}
		}
	}
	return f;
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
	l[d][r]=0;
	REP(k,h*w){
		FOR(i,1,h-1){
			FOR(j,1,w-1){
				map(s,l,i,j);
			}
		}
	}
	REP(i,h){
		REP(j,w){
			if(l[i][j]!=INF && l[d][r]<l[i][j]){
				d=i;
				r=j;
			}
		}
	}
	l=vector<vector<ll>>(h,vector<ll>(w,INF));
	l[d][r]=0;
	REP(k,h*w){
		FOR(i,1,h-1){
			FOR(j,1,w-1){
				map(s,l,i,j);
			}
		}
	}
	REP(i,h){
		REP(j,w){
			if(l[i][j]!=INF && l[d][r]<l[i][j]){
				d=i;
				r=j;
			}
		}
	}

	REP(i,h){
		REP(j,w){
			if(l[i][j]==INF)cout<<"@";
			else cout<<l[i][j];
		}
		cout<<endl;
	}
	cout<<l[d][r]-1<<endl;
	return 0;
}
