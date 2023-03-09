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
	string s;
	cin>>s;
	if(s.size()<4){
		if(s.size()==1){
			if(s[0]=='0'){
				cout<<1<<endl;
				return 0;
			}
		}
		cout<<0<<endl;
		return 0;
	}
	vector<ll> num(s.size());
	REP(i,s.size()){
		num[i]=s[i]-'0';
	}

	vector<ll> mul(10000);
	REP(i,10000)mul[i]=2019*i;

	vector<pair<ll,ll>> ansPair;
	REP(i,num.size()){
		if(num[i]==0){
			ansPair.push_back(pair<ll,ll>(i,i));
		}
	}
	REP(i,num.size()-3){
		ll num4=num[i]*1000+num[i+1]*100+num[i+2]*10+num[i+3];
		REP(j,10000){
			if(mul[j]%10000==num4){
				if(mul[j]%10==0){
					break;
				}
				ll k=0;
				while(num4%2019==0){
					k++;
					if(i+4-k<0)break;
					num4+=num[i+1-k]*pow(10,k+3);
				}
				ansPair.push_back(pair<ll,ll>(i+1-k,i+3));
				break;
			}
		}
	}
	sort(ansPair.begin(),ansPair.end());

	/*
	REP(i,ansPair.size()){
		cout<<ansPair[i].first<<" "<<ansPair[i].second<<endl;
	}*/

	vector<ll> cntEnd(num.size()+10);
	ll ans=0;
	REP(i,ansPair.size()){
		ans++;
		if(cntEnd[ansPair[i].first]!=0){
			ans+=cntEnd[ansPair[i].first];
			cntEnd[ansPair[i].second+1]=cntEnd[ansPair[i].first]+1;
		}else{
			cntEnd[ansPair[i].second+1]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
