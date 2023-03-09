#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll a,h;
	double x;
	double ans;
	cin>>a>>h>>x;
	x/=a;
	if(x>a*h/2){
		x=a*h-x;
		ans=atan((double)a*a/2/x);
		ans=ans/M_PI*180;
		ans=90-ans;
	}else{
		ans=atan((double)2*x/h/h);
		//cout<<ans;
		ans=ans/M_PI*180;
		ans=90-ans;
	}
	printf("%.10lf",ans);
	return 0;
}
