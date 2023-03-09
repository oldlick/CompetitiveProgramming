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
	vector<vector<int>> X(N,vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			X[i][j]=i*N+j+1;
		}
	}
	int tmp=X[0][0];
	for(int i=0;i<(N);i++){
		X[0][0]=X[(i+1)%(N)][(i+1)%(N)];
	}
	X[N-1][N-1]=tmp;
	
	for(int i=0;i<N;i++){
		int ans=0;
		for(int j=0;j<N;j++){
			printf("%5d   ",X[i][j]);
			ans+=X[i][j];
		}
		cout<<":"<<ans<<"/"<<ans%N<<endl;
	}
	for(int i=0;i<N;i++){
		int ans=0;
		for(int j=0;j<N;j++){
			ans+=X[j][i];
		}
		printf("%4d/%2d ",ans,ans%N);
	}
	return 0;
}
