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
	vector<ll> x(n);
	REP(i,n) cin>>x[i];
	double avg=0;
	REP(i,n)avg+=x[i];
	avg/=n;
	double sum=0;
	REP(i,n)sum+=(x[i]-avg)*(x[i]-avg);
	sum/=n;
	ll p=round(avg);//round(sqrt(avg+sum));
	//cout<<p<<endl;
	ll min=INF;
	for(int i=p-5;i<=p+5;i++){
		sum=0;
		REP(j,n)sum+=(x[j]-i)*(x[j]-i);
		if(min>sum)min=sum;
	}
	cout<<min<<endl;
	return 0;
}
