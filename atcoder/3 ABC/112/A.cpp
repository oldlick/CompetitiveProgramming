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
	ll N;
	cin>>N;
	if(N==1){
		cout<<"Hello World"<<endl;
	}else{
		ll A,B;
		cin>>A>>B;
		cout<<A+B<<endl;
	}
	return 0;
}
