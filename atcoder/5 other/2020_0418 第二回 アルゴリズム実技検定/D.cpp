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

int main(){
	string s;
	cin>>s;
	map<string,ll> ans;
	REP(h,3){
		REP(i,(signed)s.size()-h){
			//cout<<h<<" "<<i<<endl;
			REP(j,pow(2,h+1)){
				string tmp;
				tmp.reserve(3);
				REP(k,h+1){
					if((j>>k)&1){
						tmp.push_back(s[i+k]);
					}else{
						tmp.push_back('.');
					}
				}
				ans[tmp]++;
			}
		}
	}
	cout<<ans.size()<<endl;
	/*
	auto begin = ans.begin(), end = ans.end();
    for (auto iter = begin; iter != end; iter++) {
        // first: key, second: value
        cout <<"//"<< iter->first << "\n";
    }*/
	return 0;
}
