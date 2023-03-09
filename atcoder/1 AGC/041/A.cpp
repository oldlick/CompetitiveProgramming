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
	ll a,b,n;
	cin>>n>>a>>b;
	a--;b--;
	if((a-b)%2==0){
		cout<<abs((a-b)/2)<<endl;
		return 0;
	}
	ll la=a,ra=n-a-1;
	ll lb=b,rb=n-b-1;
	ll lmax=((la>lb)?la:lb);
	ll rmax=((ra>rb)?ra:rb);
	ll max,min;
	if(rmax<lmax){
		max=ra>rb?ra:rb;
		min=ra<rb?ra:rb;
	}else{
		max=la>lb?la:lb;
		min=la<lb?la:lb;
	}
	cout<<(min+max+1)/2<<endl;
	return 0;
}
