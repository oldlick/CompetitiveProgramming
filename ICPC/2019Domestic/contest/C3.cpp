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
    //cout<<s.size()<<endl;
    //for(auto &x:sub)cout<<x.first<<" ";
    //cout<<endl;
    set<ll> ans;
    bool empty=true;
    rep(i,n){
        if(s.count(a[i])==0){
            set<ll> need;
            for(auto &x:s){
                need.insert(a[i]);
                need.insert(abs(x - a[i]));
                need.insert(x + a[i]);
            }
            set<ll> tmp;
            if(empty==true){
                for(auto &x:need)ans.insert(x);
                empty=false;
            }else{
                for(auto &x:need)if(ans.count(x)!=0)tmp.insert(x);
                ans.swap(tmp);
            }
        }
    }
    //cout<<ans.size()<<endl;
    //cout<<cnt<<endl;
    //for(auto &x:ans)cout<<x.first<<"["<<x.second<<endl;
    if(empty==true){
        cout<<0<<endl;
        return true;
    }else{
        if(ans.size()==0){
            cout<<-1<<endl;
            return true;
        }else{
            cout<<*ans.begin()<<endl;
            return true;
        }
    }
    return true;
}

int main(){
    while(solve());
    return 0;
}