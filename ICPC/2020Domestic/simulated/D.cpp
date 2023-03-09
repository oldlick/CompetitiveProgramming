#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)n; ++i)
#define FOR(i,s,n) for(int i=s; i<(int)n; ++i)
using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll LINF = 1LL<<60;


bool solve(){
    string s;
    cin>>s;
    if(s=="#")return false;
    ll n=s.size();
    V<ll> cnt;
    char old=0;
    ll tmp=0;
    REP(i,n){
        if(s[i]==old)tmp++;
        else {
            cnt.push_back(tmp);
            tmp=0;
        }
    }
    cnt.push_back(tmp);
    tmp=0;
    if(cnt.size()%2!=0)cnt.push_back(tmp);
    ll re=0;
    REP(i,cnt.size()/2){
        re+=cnt[i*2];
        
    }
    return true;
}

int main(){
    while(solve());
}