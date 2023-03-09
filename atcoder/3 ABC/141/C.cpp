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
	ll N,K,Q;
	cin>>N>>K>>Q;
	K-=Q;
	vector<ll> A(N+1,0);
	for(int i=0;i<Q;i++){
		int tmp;
		cin>>tmp;
		A[tmp]++;
	}
	for(int i=1;i<=N;i++){
		if(A[i]+K>0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
