#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,n) for(int i=s;i<(int)n;++i)
using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr int INF = 1e9+7;
constexpr ll LINF = 1LL<<60;

void solve(){
    ll d;
    cin>>d;
    double tmp=pow((double)d/2,0.5);
    cout<<tmp<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll m=0;
    cin>>m;
    rep(i,m){
        solve();
    }
    return 0;
}
