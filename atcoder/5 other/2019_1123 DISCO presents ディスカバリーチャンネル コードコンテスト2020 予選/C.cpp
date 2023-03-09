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
#define INF 1e18;
int main(){
	ll H,W,K;
	cin>>H>>W>>K;
	vector<vector<ll>> s(H,vector<ll>(W,0));
	ll k=1;
	REP(i,H){
		REP(j,W){
			char tmp;
			cin>>tmp;
			if(tmp=='#'){
				s[i][j]=k;
				k++;
			}
		}
	}
	//test(s);
	
	REP(i,H){
		ll now=0;
		ll first=0;
		REP(j,W){
			if(s[i][j]!=0){
				now=s[i][j];
				if(first==0)first=s[i][j];
			}else{
				s[i][j]=now;
			}
			//cout<<s[i][j];//
		}
		REP(j,W){
			if(s[i][j]!=0){
				break;
			}else{
				s[i][j]=first;
			}
		}
		//cout<<endl;//
		if(s[i][0]==0 && i!=0){
			REP(j,W)s[i][j]=s[i-1][j];
		}
	}
	REP(i,H){
		if(s[i][0]!=0){
			for(ll j=i;j>0;j--){
				REP(m,W)s[j-1][m]=s[j][m];
			}
			break;
		}
	}
	REP(i,H){
		REP(j,W){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
