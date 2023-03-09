#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

constexpr ll LINF = 1LL<<60;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
ll m=0;
ll hoge(V<ll>&d,ll minIdx,ll maxIdx){
    cout<<minIdx<<":"<<maxIdx<<endl;
    /*rep(i,d.size()){
        if(minIdx<=i && i<maxIdx)cout<<d[i]<<" ";
        else cout<<"  ";
    }*/
    ll ret=LINF;
    if(maxIdx-minIdx<=2){
        ret=0;
        reps(i,minIdx,maxIdx){
            ret=max(ret,d[i]);
        }
        //cout<<"ans:"<<ret<<endl;
        return ret;
    }
    set<ll> d_(d.begin()+minIdx,d.begin()+maxIdx);
    for(auto &x:d_){
        ll now=-1;
        ll sum=0;
        V<ll> tmp=d;
        reps(j,minIdx,maxIdx){
            tmp[j]-=x;
            if(tmp[j]<0)tmp[j]+=m;
            if(tmp[j]==0){
                //cout<<endl<<"--"<<endl;
                if(now+1<j)sum+=hoge(tmp,now+1,j);
                now=j;
            }
        }
        sum+=hoge(tmp,now+1,maxIdx);
        sum+=x;
        //cout<<"test :"<<sum<<endl;
        if(ret>sum)ret=sum;
    }
    //cout<<"return :"<<ret<<endl;
    return ret;
}

bool solve(){
    ll n;
    cin>>n>>m;
    if(n==0)return false;
    V<ll> a(n),b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n){
        b[i]-=a[i];
        if(b[i]<0)b[i]+=m;
    }
    cout<<hoge(b,0,n)<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}