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
	ll n,m,v,p;
	cin>>n>>m>>v>>p;
	vector<ll> a(n);
	REP(i, n){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),greater<int>());												//n log n

	//cout << "a: ";REP(i, a.size()) cout<<a[i]<<" ";cout << endl;//

	vector<vector<ll>> num;
	ll old=-1;
	REP(i,n){											// n
		if(old==a[i]){
			num[num.size()-1][1]++;
		}else{
			num.push_back(vector<ll>(1,0));
			num[num.size()-1][0]=a[i];
			num[num.size()-1][1]=1;
			old=a[i];
		}
	}

	//cout << "num: ";REP(i, num.size()) cout<<num[i][0]<<","<<num[i][1]<<"/";cout << endl;//

	ll line=a[p-1];

	//cout<<"line "<<line<<endl;//
	////cout<<v<<"<="<<n-line_n<<endl;//

	if(v<=p){
		ll ans=p;
		FOR(i,p,n){
			if(line<=a[i]+m){
				//cout<<line<<"<="<<a[i]+m<<" ok__ "<<i<<endl;//
				ans++;
			}
		}
		cout<<ans<<endl;
	}else{
		ll ans=0;
		FOR(i,0,num.size()){
			ll haveto=0;
			ll j=i;
			while(1){
				if(j<0)break;
				if(num[j][0]>line)break;
				haveto+=(num[j][0]-num[i][0])*num[j][1];
				j--;
			}
			if(haveto<=m*(n-v)){
				//cout<<haveto<<"<="<<m*(n-v)<<"(="<<m<<"*"<<(n-v)<<") ok "<<i<<endl;//
				ans+=num[i][1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}