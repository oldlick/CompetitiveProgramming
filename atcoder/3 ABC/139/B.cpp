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
	int A,B;
	cin>>A>>B;
	int now=1;
	int ans=0;
	while(now*A<=B){
		ans+=now;
		now*=A;
	}
	while(now<B){
		ans++;
		now+=A-1;
	}
	cout<<ans;
	return 0;
}
