#include <cstdio>
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
	vector<char> S(2*N);
	for(int i=0;i<2*N;i++){
		cin>>S[i];
	}
	int l=0,r=2*N-1;
	vector<int> T(2*N);
	for(int i=1;i<=N;i++){
		while(1){
			T[l]=i;
			l++;
			if(S[l]!=S[l-1]) break;
		}
		while(1){
			T[r]=i;
			r--;
			if(S[r]!=S[r+1]) break;
		}
		if(r<l) break;
	}
	for(int i=0;i<2*N;i++){
		cout<<T[i]<<' ';
	}
	return 0;
}
