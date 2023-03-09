#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)

using namespace std;
using ll = long long;

bool solve(){
    ll n,m;
    cin>>n>>m;
    if(n==0)return false;
    vector<ll> d(n);
    rep(i,m){
        rep(j,n){
            ll tmp;
            cin>>tmp;
            d[j]+=tmp;
        }
    }
    ll max=0;
    rep(i,n)if(max<d[i])max=d[i];
    cout<<max<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}