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

void add(vector<ll> &n,ll p){
	n[p]++;
	FOR(i,p,n.size()){
		if(n[i]==10){
			n[i]=0;
			if(i==n.size()-1)n.push_back(0);
			n[i+1]++;
		}else{
			return;
		}
	}
}
void next(vector<ll> &n){
	ll i=0;
	while(1){
		if(i==n.size()-1){
			if(n[i]==9){
				n.push_back(0);
				i++;
			}
			break;
		}
		if(n[i+1]+1!=n[i] && n[i]!=9){
			break;
		}
		i++;
	}
	n[i]++;
	ll tmp=n[i];
	while(1){
		i--;
		tmp--;
		if(tmp<0)tmp=0;
		if(i<0)break;
		n[i]=tmp;
	}
}
int main(){
	ll n; cin>>n;
	vector<ll> num(1,0);
	REP(i,n){
		next(num);
		//cout << "num: "; REP(i,(signed)num.size()) cout<<num[i]<<" "; cout << endl;
	}
	REP(i,(signed)num.size()){
		cout<<num[num.size()-1-i];
	}
	cout << endl;
	return 0;
}
