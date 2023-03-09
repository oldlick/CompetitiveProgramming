#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 3e18;
int mod = 1e9+7;
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0,-1};
int dp[2005][2005][5];
signed main() {
    int H,W;
    cin >> H >> W;
    vector<string>S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.') {
                int res = dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
                res %= mod;
                if(i == 0 && j == 0) {
                    res = 0;
                }
                dp[i+1][j][0] += dp[i][j][0]+res;
                dp[i+1][j][0] %= mod;
                dp[i][j+1][1] += dp[i][j][1]+res;
                dp[i][j+1][1] %= mod;
                dp[i+1][j+1][2] += dp[i][j][2]+res;
                dp[i+1][j+1][2] %= mod;
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << (dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%mod << " ";
        }
        cout<<endl;
    }
    
    cout << (dp[H-1][W-1][0]+dp[H-1][W-1][1]+dp[H-1][W-1][2])%mod << endl;
}
