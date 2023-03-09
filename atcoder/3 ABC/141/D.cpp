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

int main(){
	ll N,M;
	cin>>N>>M;
	priority_queue<double> A;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		A.push(tmp);
	}
	for(int i=0;i<M;i++){
		double tmp=A.top();
		A.pop();
		A.push(tmp/2);
	}
	ll ans=0;
	for(int i=0;i<N;i++){
		ans+=(ll)A.top();
		A.pop();
	}
	cout<<ans;
	return 0;
}
