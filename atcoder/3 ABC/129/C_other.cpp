#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
#define MOD  1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int dp[100001] = { 1 };
bool ok[100001];
int main(){
	int n, m;
	int tmp;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) ok[i] = true;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		ok[tmp] = false;
	}
	if (ok[1]) {
		dp[1] = 1;
	}
	for (int i = 2; i <=n; i++) {
		dp[i] %= MOD;
		if (ok[i - 1]) dp[i] += (dp[i - 1] % MOD);
		dp[i] %= MOD;
		if (ok[i - 2]) dp[i] += (dp[i - 2] % MOD);
		dp[i] %= MOD;
	}
	dp[n] %= MOD;
	cout << dp[n] << endl;
	return 0;
}
