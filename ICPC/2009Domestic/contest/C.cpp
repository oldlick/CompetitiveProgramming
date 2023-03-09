#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
bool check(V<string> &s,V<ll> &use){
    V<ll> d(s.size());
    rep(i,s.size()){
        if(use[s[i][0]-'A']==0 && s[i].size()!=1)return false;
        rep(j,s[i].size())d[i]=d[i]*10+use[s[i][j]-'A'];
    }
    ll sum=0;
    rep(i,d.size()-1)sum+=d[i];
    if(sum==d.back())return true;
    return false;
}
bool solve(){
    ll n;
    cin>>n;
    if(n==0)return false;
    V<string> s(n);
    rep(i,n)cin>>s[i];
    map<ll,ll> cnt;
    rep(i,n)rep(j,s[i].size()){
        if(!cnt.count(s[i][j])){
            cnt[s[i][j]]=cnt.size();
        }
        s[i][j]=cnt[s[i][j]]+'A';
    }
    //rep(i,n)cout<<s[i]<<endl;
    V<ll> sel(10);
    rep(i,cnt.size())sel[9-i]=1;
    ll ans=0;
    do{
        V<ll> use;
        rep(i,10)if(sel[i]==1)use.push_back(i);
        do{
            if(check(s,use))ans++;
        }while(next_permutation(use.begin(),use.end()));
    }while(next_permutation(sel.begin(),sel.end()));
    cout<<ans<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}