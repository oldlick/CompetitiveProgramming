#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
bool solve(){
    ll n,m;
    cin>>n>>m;
    if(n==0)return false;
    vector<ll> a(n),w(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>w[i];
    ll end=1<<m;
    map<ll,ll> add;
    reps(i,1,end){
        ll tmp=0;
        rep(j,m){
            if(i&(1<<j))tmp+=w[j];
        }
        add[tmp]++;
    }
    //for(auto &x:add)cout<<x.first<<" ";
    //cout<<endl;
    map<ll,ll> sub;
    for(auto x=add.begin();x!=add.end();x++){
        sub[x->first]++;
        for(auto y=next(x);y!=add.end();y++){
            sub[y->first - x->first]++;
        }
    }
    //for(auto &x:sub)cout<<x.first<<" ";
    //cout<<endl;
    map<ll,ll> ans;
    ll cnt=0;
    rep(i,n){
        if(sub.count(a[i])==0){
            set<ll> tmp;
            for(auto &x:sub){
                tmp.insert(abs(x.first - a[i]));
                tmp.insert(x.first + a[i]);
            }
            for(auto &x:tmp)ans[x]++;
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    //for(auto &x:ans)cout<<x.first<<"["<<x.second<<endl;
    if(cnt==0){
        cout<<0<<endl;
        return true;
    }
    for(auto &x:ans){
        if(x.second==cnt){
            cout<<x.first<<endl;
            return true;
        }
    }
    cout<<-1<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}