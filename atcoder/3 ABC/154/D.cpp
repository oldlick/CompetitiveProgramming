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
	vector<double> p(n);
	REP(i,n) cin>>p[i];

	vector<double> sum(n-k+1);
	REP(i,n) p[i]=(p[i]+1)/2;
	REP(i,k){
		sum[0]+=p[i];
	}
	FOR(i,1,n){
		if(i-1+k>=n)break;
		sum[i]=sum[i-1]-p[i-1]+p[i-1+k];
	}
	//cout << "sum: "; REP(i,(signed)sum.size()) cout<<sum[i]<<" "; cout << endl; //----------cout----------//

	double max=0;
	REP(i,sum.size()){
		if(sum[i]>max)max=sum[i];
	}
	printf("%.12lf\n",max);
	return 0;
}
