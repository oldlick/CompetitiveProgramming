#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	int N;
	cin>>N;
	ll ans=0;
	for(ll i=1;i<=N-1;i++){
		ll tmp=i*1000;
		if(sqrt(tmp*i)==0){
			tmp=100;
		}
		ans+=tmp/1000;
	}
	cout<<ans<<endl;
	return 0;
}
