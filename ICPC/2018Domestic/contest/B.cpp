#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

void fold(VV<ll> &d){
    ll a,b;
    cin>>a>>b;
    ll m=d.size(),n=d[0].size();
    if(a==1){
        n=max(b*2,n);
        rep(i,m)d[i].resize(n);
        rep(i,m){
            rep(j,b){
                d[i][b*2-1-j]+=d[i][j];
                d[i][j]=0;
            }
        }
        rep(i,m){
            rep(j,n/2){
                swap(d[i][j],d[i][n-1-j]);
            }
        }
        n=max(b,n-b);
        rep(i,m){
            d[i].resize(n);
        }
        rep(i,m){
            rep(j,n/2){
                swap(d[i][j],d[i][n-1-j]);
            }
        }
    }else{
        m=max(b*2,m);
        d.resize(m,V<ll>(n));
        rep(i,b){
            rep(j,n){
                d[b*2-1-i][j]+=d[i][j];
                d[i][j]=0;
            }
        }
        rep(i,m/2){
            rep(j,n){
                swap(d[i][j],d[m-1-i][j]);
            }
        }
        m=max(b,m-b);
        d.resize(m);
        rep(i,m/2){
            rep(j,n){
                swap(d[i][j],d[m-1-i][j]);
            }
        }
    }
}
bool solve(){
    ll n,m,t,p;
    cin>>n>>m>>t>>p;
    if(n==0)return false;
    VV<ll> d(m,V<ll>(n,1));
    rep(i,t){
        fold(d);
        /*
        rep(j,d.size()){
            rep(k,d[j].size()){
                cout<<d[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<"--"<<endl;*/
    }
    rep(i,p){
        ll a,b;
        cin>>a>>b;
        cout<<d[b][a]<<endl;
    }
    return true;
}

int main(){
    while(solve());
    return 0;
}