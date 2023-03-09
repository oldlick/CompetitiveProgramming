#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

ll check(string s){
    ll cnt=0;
    rep(i,s.size()){
        if(s[i]!='.')break;
        cnt++;
    }
    return cnt;
}
bool solve(){
    ll n;
    cin>>n;
    if(n==0)return false;
    deque<ll> d;
    ll cnt=0;
    rep(i,n+1){
        ll tmp=0;
        string in;
        if(i!=n){
            cin>>in;
            tmp=check(in);
        }
        rep(i,cnt-tmp){
            ll tmp1=0,tmp2=1;
            while(1){
                ll now=d.back();
                d.pop_back();
                if(now==-1){
                    d.push_back(tmp1);
                    break;
                }
                if(now==-2){
                    d.push_back(tmp2);
                    break;
                }
                tmp1+=now;
                tmp2*=now;
            }
        }
        cnt=tmp;
        if(i!=n){
            if(in.back()=='+')d.push_back(-1);
            else if(in.back()=='*')d.push_back(-2);
            else d.push_back(in.back()-'0');
        }
        //for(auto &x:d)cout<<x<<" ";
        //cout<<endl;
    }
    cout<<d.back()<<endl;
    return true;
}

int main(){
    while(solve());
    return 0;
}