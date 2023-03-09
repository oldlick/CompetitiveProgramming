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
	string S;
	cin>>S;
	if(S=="SUN"){
		cout<<7<<endl;
	}else if(S=="MON"){
		cout<<6<<endl;
	}else if(S=="TUE"){
		cout<<5<<endl;
	}else if(S=="WED"){
		cout<<4<<endl;
	}else if(S=="THU"){
		cout<<3<<endl;
	}else if(S=="FRI"){
		cout<<2<<endl;
	}else if(S=="SAT"){
		cout<<1<<endl;
	}
	return 0;
}
