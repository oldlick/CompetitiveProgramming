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
	ll x; cin>>x;
	vector<ll> num;
	num.reserve(100001);
	REP(i,100001){
		if(pow(i,5)>INF)break;
		num.push_back(pow(i,5));
	}
	//cout << "num: "; REP(i,num.size()) cout<<num[i]<<" "; cout << endl; //----------cout----------//

	REP(i,num.size()){
		auto it=lower_bound(num.begin(),num.end(),x+num[i]);
		//cout<<*it<<" "<<x+num[i]<<endl;
		if(num[it-num.begin()]==x+num[i]){
			cout<<it-num.begin()<<" "<<i<<endl;
			return 0;
		}
		
		it=lower_bound(num.begin(),num.end(),x-num[i]);
		//cout<<*it<<" "<<x-num[i]<<endl;
		if(num[it-num.begin()]==x-num[i]){
			cout<<it-num.begin()<<" "<<-i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
