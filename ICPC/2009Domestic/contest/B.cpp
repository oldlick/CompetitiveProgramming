#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

void dfs(VV<ll> &d,ll a,ll b,ll now){
    d[a][b]=now+2;
    reps(i,-1,2)reps(j,-1,2){
        if(d[a+i][b+j]==1)dfs(d,a+i,b+j,now);
    }
}
bool solve(){
    ll w,h;
    cin>>w>>h;
    if(w==0)return false;
    w+=2;h+=2;
    VV<ll> d(h,V<ll>(w));
    rep(i,h-2)rep(j,w-2){
        ll tmp=0;
        cin>>tmp;
        d[i+1][j+1]=tmp;
    }
    ll now=0;
    rep(i,h)rep(j,w){
        if(d[i][j]!=1)continue;
        dfs(d,i,j,now);
        now++;
    }/*
    rep(i,h){rep(j,w){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<now<<endl;
    return true;
}


int main(){
    while(solve());
    return 0;
}