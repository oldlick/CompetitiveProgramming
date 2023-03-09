#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

void solve(){
    string s;
    cin>>s;
    map<string,ll> m;
    rep(i,s.size()-1){ //s.size()
        string t1,t2,t1_,t2_;
        t1=s.substr(0,i+1); //s.size()
        t2=s.substr(i+1,s.size()-i-1);
        //cout<<t1<<" "<<t2<<endl;
        t1_=t1;
        t2_=t2;
        reverse(t1_.begin(),t1_.end()); //s.size()
        reverse(t2_.begin(),t2_.end());
        m[t1+t2]=1; //log(s.size())
        m[t1_+t2]=1;
        m[t1+t2_]=1;
        m[t1_+t2_]=1;
        m[t2+t1]=1;
        m[t2_+t1]=1;
        m[t2+t1_]=1;
        m[t2_+t1_]=1;
    }
    cout<<m.size()<<endl;
}


int main(){
    ll n;
    cin>>n;
    rep(i,n){
        solve();
    }
    return 0;
}