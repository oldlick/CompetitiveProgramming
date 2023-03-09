#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	ll N;
	cin>>N;
	char S[100010];
	cin>>S;
	ll ans=0;
	char now=0;
	rep(i,N){
		if(S[i]!=now){
			ans++;
			now=S[i];
		}
	}
	cout<<ans;
	return 0;
}
