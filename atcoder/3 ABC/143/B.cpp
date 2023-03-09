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
	vector<ll> d(N);
	rep(i,N) cin>>d[i];
	ll ans=0;
	rep(i,N){
		rep(j,N){
			if(i<j){
				ans+=d[i]*d[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
