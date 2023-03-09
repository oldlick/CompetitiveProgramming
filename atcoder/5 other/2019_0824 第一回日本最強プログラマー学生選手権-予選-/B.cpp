#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

#define mod (1000000000+7)

int main(){
	ll N,K;
	cin>>N>>K;
	vector<ll> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	vector<pair<ll,ll>> cntA(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[j]<A[i]){
				cntA[i].first++;
				if(i<j){
					cntA[i].second++;
				}
			}
		}
		//cout<<cntA[i].first<<cntA[i].second<<endl;
	}
	ll ans=0;
	for(int i=0;i<N;i++){
		ans+=(cntA[i].second*K)%mod;
		ans%=mod;
		ans+=((K*(K-1)/2)%mod)*cntA[i].first%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
