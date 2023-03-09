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
	ll k; cin>>k;
	vector<ll> a(n);
	REP(i,n){
		cin>>a[i];
		a[i]--;
	}
	vector<ll> num(n+1,-1);
	ll cur=0,loop=0,end=0;
	num[cur]=0;
	//cout<<"cur "<<cur<<endl;
	FOR(i,1,k+1){
		cur=a[cur];
		//cout<<i<<"cur "<<cur<<endl;
		if(num[cur]!=-1){
			loop=(i-num[cur]);
			end=k-i;
			break;
		}
		num[cur]=i;
	}
	if(loop==0){
		cout<<cur+1<<endl;
		return 0;
	}
	//cout<<loop<<endl;
	end%=loop;
	REP(i,end){
		cur=a[cur];
	}
	cout<<cur+1<<endl;
	return 0;
}
