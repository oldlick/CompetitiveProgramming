#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
const int MOD = (int)1e9 + 7;
const int MAX_N = 10000;  // 400MB
using namespace std;

long long nCr(int n,int r){/*
	if(r>n-r)r=n-r;
	if(r==0 || n==r){
		return 1;
	}
	return (nCr(n-1,r)+nCr(n-1,r-1))%MOD;*/
    static bool done[MAX_N + 1][MAX_N / 2 + 2];
    static long long dp[MAX_N + 1][MAX_N / 2 + 2];  // 400MB
    if (n < 0 || r < 0 || n < r) return 0;
    if (r == 0) return 1;
    if (r > n - r) r = n - r;
    long long &res = dp[n][r];
    if (done[n][r]) return res;
    done[n][r] = true;
    return res = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
}

int main(){
	int R=0,B=0;
	cin>>R>>B;
	R-=B;
	for(int i=1;i<=B;i++){
		if(R+1<i){
			cout<<"0"<<endl;
			continue;
		}
		int ans=1;
		ans=(nCr(B-1,i-1)*nCr(R+1,i))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
