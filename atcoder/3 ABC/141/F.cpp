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
	ll N,R,B;
	cin>>N;
	vector<ll> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	for(int i=N-1;i>=0;i--){
		//cout<<A[i]<<':'<<endl;
		if( ((R^A[i])-R)>((B^A[i])-B) ) R^=A[i];
		else B^=A[i];
		//cout<<B<<'/'<<R<<endl;
	}
	cout<<B+R;
	return 0;
}
