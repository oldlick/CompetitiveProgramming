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
double len(int x1,int x2,int y1,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int N;
	cin>>N;
	vector<int> x(N),y(N);
	REP(i,N) cin>>x[i]>>y[i];
	vector<int> n(N);
	REP(i,N) n[i]=i;
	double sum=0;
	ll times=0;
	do{
		REP(i,N-1){
			//cout<<n[i]<<" ";
			sum+=len(x[n[i]],x[n[i+1]],y[n[i]],y[n[i+1]]);
		}
		//cout<<n[N-1]<<" ";
		//cout<<endl;
		times++;
	}while(next_permutation(n.begin(),n.end()));
	sum/=times;
	printf("%.10lf",sum);
	return 0;
}
