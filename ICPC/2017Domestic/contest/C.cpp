#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
ll check(VV<ll> &d,ll sh,ll gh,ll sw,ll gw){
    ll min=LINF;
    reps(i,sh,gh+1){
        if(min>d[i][gw])min=d[i][gw];
        if(min>d[i][sw])min=d[i][sw];
    }
    reps(i,sw,gw+1){
        if(min>d[gh][i])min=d[gh][i];
        if(min>d[sh][i])min=d[sh][i];
    }
    //cout<<min<<endl;
    ll ret=0;
    reps(i,sh+1,gh)reps(j,sw+1,gw){
        if(d[i][j]>=min)return 0;
        ret+=min-d[i][j];
    }
    return ret;
}
bool solve(){
    ll h,w;
    cin>>h>>w;
    if(h==0)return false;
    VV<ll> d(h,V<ll>(w));
    rep(i,h)rep(j,w){
        cin>>d[i][j];
    }
    ll ans=0;
    rep(sh,h)reps(gh,sh+2,h){
        rep(sw,w)reps(gw,sw+2,w){
            //cout<<sh<<" "<<gh<<" "<<sw<<" "<<gw<<endl;
            ll tmp=check(d,sh,gh,sw,gw);
            if(ans<tmp)ans=tmp;
        }
    }
    cout<<ans<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}