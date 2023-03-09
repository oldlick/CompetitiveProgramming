#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

#define MOD (ll)(1e9+7);
ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;

map<ll,ll> fact(ll a){
	map<ll,ll> ans;
	ll end=sqrt(a);
	FOR(i,2,end+1){
		while(a%i==0){
			a/=i;
			ans[i]++;
			cnt1++;
		}
		if(a==1)break;
	}
	if(a!=1){
		ans[a]++;
	}
	return ans;
}

map<ll,ll> calcLcm(map<ll,ll> a,map<ll,ll> b){
	for(auto it:a){
		b[it.first]=max(b[it.first],it.second);
		cnt2++;
	}
	return b;
}
ll power(ll a,ll b){
	static map<ll,vector<ll>> list;
	if(list[a].size()>b){
		//cout<<a<<"^"<<b<<"="<<list[a][b]<<endl;
		return list[a][b];
	}
	if(list[a].size()==0){
		list[a].reserve(b+1);
		list[a].push_back(1);
		list[a].push_back(a);
	}
	while(list[a].size()<=b){
		list[a].push_back(list[a].back()*a);
		list[a].back()%=MOD;
	}
	//cout<<a<<"^"<<b<<"="<<list[a].back()<<endl;
	return list[a].back();
}
ll factToInt(map<ll,ll> a){
	ll ans=1;
	for(auto it:a){
		ans*=power(it.first,it.second);
		ans%=MOD;
		cnt3++;
	}
	return ans;
}
map<ll,ll> divFact(map<ll,ll> a,const map<ll,ll> &b){
	for(auto it:b){
		a[it.first]-=it.second;
		cnt4++;
	}
	return a;
}

int main(){
	ll n; cin>>n;
	vector<map<ll,ll>> a;
	map<ll,ll> lcm;
	REP(i,n){
		ll tmp;cin>>tmp;
		a.push_back(fact(tmp));
		lcm=calcLcm(a.back(),lcm);
		cout<<i<<endl;
	}
	for(auto it:lcm){
		power(it.first,it.second);
	}
	ll ans=0;
	REP(i,n){
		ans+=factToInt(divFact(lcm,a[i]));
		ans%=MOD;
	}
	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<endl;
	cout<<ans<<endl;
	return 0;
}