#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

bool solve(){
    ll n;
    cin>>n;
    if(n==0)return false;
    V<string> s(n);
    rep(i,n) cin>>s[i];
    V<ll> d(26);
    rep(i,n){
        d[s[i][0]-'A']++;
        V<ll> tmp=d;
        sort(tmp.rbegin(),tmp.rend());
        if(tmp[0]>tmp[1]+(n-i-1)){
            rep(j,26)if(d[j]==tmp[0])cout<<(char)('A'+j)<<" "<<i+1<<endl;
            return true;
        }
    }
    cout<<"TIE"<<endl;
    return true;
}


int main(){
    while(solve());
    return 0;
}