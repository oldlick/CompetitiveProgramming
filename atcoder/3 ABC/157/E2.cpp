#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll n; cin>>n;
	string S; cin>>S;
	ll q; cin>>q;
	cout<<q<<endl;
	vector<vector<char>> Q(q,vector<char>(3,0));
	REP(i,q){
		REP(j,3){
			cin>>Q[i][j];
		}
	}
	vector<ll> s(n);
	REP(i,n){
		s[i]=S[i]-'a';
	}
	vector<list<int>> num(26);
	REP(i,n){
		num[s[i]].push_back(i+1);
	}
	/*
	REP(i,(signed)num.size()){
		REP(j,(signed)num[i].size()){
			cout<<num[i][j]<<" "; //----------cout----------//
		}
		cout << endl;
	}*/
	
	REP(i,q){
		char a,b,c;
		ll ans=0;
		a=Q[i][0];
		b=Q[i][1];
		c=Q[i][2];
		if(a=='1'){
			b-='0';
			b--;
			c-='a';
			int old=s[b];
			s[b]=c;
			int now=s[b];
			
			auto it=lower_bound(num[old].begin(),num[old].end(),b);
			num[old].erase(it);
			it=lower_bound(num[now].begin(),num[now].end(),b);
			num[old].insert(it,b);
			
		}else{/*
			b-='0';
			c-='0';
			REP(j,26){
				int it1=lower_bound(num[j].begin(),num[j].end(),b);
				auto it2=lower_bound(num[j].begin(),num[j].end(),c);
				if(it1-num[j].begin()<=it2-num[j].begin() && it1!=num[j].begin()){
					ans++;
				}
			}*/
			cout<<ans;
		}
	}
	return 0;
}