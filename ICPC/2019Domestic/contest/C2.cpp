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
    ll end=pow(3,m);
    set<ll> s;
    reps(i,1,end){
        ll sum=0;
        ll x=i;
        rep(j,m){
            if(x%3==1){
                sum+=w[j];
            }else if(x%3==2){
                sum-=w[j];
            }
            x/=3;
        }
        if(sum>0)s.insert(sum);
    }
    cout<<s.size()<<endl;
    //for(auto &x:sub)cout<<x.first<<" ";
    //cout<<endl;
    map<ll,ll> ans;
    ll cnt=0;
    rep(i,n){
        if(s.count(a[i])==0){
            set<ll> tmp;
            for(auto &x:s){
                tmp.insert(a[i]);
                tmp.insert(abs(x - a[i]));
                tmp.insert(x + a[i]);
            }
            for(auto &x:tmp)ans[x]++;
            cnt++;
        }
    }
    cout<<ans.size()<<endl;
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