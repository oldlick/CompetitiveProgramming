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
	vector<ll>n(s.size());
	ll lsum=0,rsum=0;
	REP(i,s.size()){
		n[i]=s[s.size()-i-1]-'0';
		lsum+=n[i];
	}
	ll ans=lsum;
		//cout<<lsum<<"/"<<rsum<<endl;//
	REP(i,n.size()){
		lsum-=n[i];
		if(i==0)lsum++;
		rsum+=9-n[i];
		if(i==0)rsum++;
		//cout<<lsum<<"/"<<rsum<<endl;//
		//cout << "n: "; REP(i,(signed)n.size()) cout<<n[n.size()-i-1]<<" "; cout << endl; //----------cout----------//

		if(ans>lsum+rsum)ans=lsum+rsum;
	}
	cout<<ans<<endl;

	return 0;
}
