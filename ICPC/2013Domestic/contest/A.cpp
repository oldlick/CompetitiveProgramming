#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

bool check(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second){
        return true;
    }
    if(a.first*a.first+a.second*a.second==b.first*b.first+b.second*b.second){
        if(a.first<b.first) return true;
    }
    return false;
}
bool solve(){
    ll h,w;
    cin>>h>>w;
    if(h==0)return false;
    pair<ll,ll> test=make_pair(h,w);
    pair<ll,ll> ans=make_pair(-1,-1);
    reps(i,1,151)reps(j,i+1,151){
        pair<ll,ll> now=make_pair(i,j);
        if(!check(test,now))continue;
        if(ans==pair<ll,ll>(-1,-1)){
            ans=now;
            continue;
        }
        if(check(now,ans))ans=now;
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}