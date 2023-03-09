#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

ll ans=0;

bool check(ll x1,ll y1,ll r1,ll x2,ll y2,ll r2){
    ll dr=(r1+r2);
    ll dx=abs(x1-x2);
    ll dy=abs(y1-y2);
    if(dr*dr>dx*dx+dy*dy)return true;
    return false;
}

void dfs(V<ll> &x,V<ll> &y,V<ll> &r,V<ll> &c,V<ll> &m){
    ll n=x.size();
    VV<ll> list(4);
    rep(i,n){
        if(m[i]!=0)continue;
        bool f=false;
        rep(j,i){
            if(m[j]==1)continue;
            if(check(x[i],y[i],r[i],x[j],y[j],r[j])){
                f=true;
                break;
            }
        }
        if(f==false)list[c[i]].push_back(i);
    }
    bool f=false;
    for(auto& i:list){
        if(i.size()<=1){
            i.clear();
            i.push_back(-1);
        }else if(i.size()%2==0){
            rep(j,i.size())m[i[j]]=2;
            i.clear();
            i.push_back(-1);
            f=true;
        }else{
            rep(j,i.size())m[i[j]]=2;
            f=true;
        }
    }
    }else{
        ll cnt=0;
        rep(i,n)if(m[i]==2)cnt++;
        if(cnt>ans)ans=cnt;
        rep(i,n)cout<<m[i]<<" ";
        cout<<" "<<cnt<<endl;
    }
}
bool solve(){
    ll n;
    cin>>n;
    if(n==0)return false;
    V<ll> x(n),y(n),r(n),c(n),m(n);
    rep(i,n){
        ll x_,y_,r_,c_;
        cin>>x_>>y_>>r_>>c_;
        x[i]=x_;
        y[i]=y_;
        r[i]=r_;
        c[i]=c_-1;
    }
    ans=0;
    dfs(x,y,r,c,m);
    cout<<ans<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}