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

string join(string a,string b){
	ll min=a.size()+b.size();
	ll min_idx=-1;
	for(ll i=0;i<a.size();i++){
		ll tmp=i;
		ll f=0;
		FOR(j,0,b.size()){
			if(i+j>=a.size())break;
			if(a[j+i]!='?' && b[i]!='?' && a[j+i]!=b[j]){
				f=1;
				break;
			}
		}
		if(f==0){
			if(min>tmp){
				min=tmp;
				min_idx=i;
			}
		}
	}
	if(min_idx==-1){
		return a+b;
	}else{
		string ans;
		FOR(j,0,min_idx){
			ans.push_back(a[j]);
		}
		FOR(j,0,b.size()){
			if(min_idx+j>=a.size())ans.push_back(b[j]);
			else if(b[j]!='?')ans.push_back(b[j]);
			else ans.push_back(a[min_idx+j]);
		}
		return ans;
	}
}

int main(){
	string a,b,c;
	cin>>a>>b>>c;
	ll ans=INF;
	string tmp;
	tmp=join(a,join(b,c));
	cout<<tmp<<endl;
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	tmp=join(a,join(c,b));
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	tmp=join(b,join(a,c));
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	tmp=join(b,join(c,a));
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	tmp=join(c,join(a,b));
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	tmp=join(c,join(b,a));
	if(ans>tmp.size())ans=tmp.size();
	cout<<tmp<<endl;
	cout<<ans<<endl;
	return 0;
}
