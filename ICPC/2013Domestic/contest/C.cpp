#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,s,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;
constexpr ll LINF = 1LL<<60;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

bool solve(){
    string s;
    cin>>s;
    V<ll> d;
    rep(i,s.size()){
        if(s[i]=='[')d.push_back(-1);
        else if(s[i]==']'){
            if(d.size()!=0 && d.back()>=0){
                d.back()=ceil((double)d.back()/2);
            }
            d.push_back(-2);
        }else {
            if(d.size()==0 || d.back()<0){
                d.push_back(s[i]-'0');
            }else{
                d.back()=d.back()*10+s[i]-'0';
            }
        }
    }
    rep(i,d.size()){
        if(d[i]!=-2)continue;
        V<ll> tmp;
        ll r=i;
        for(i--;d[i]>=0;i--){
            tmp.push_back(d[i]);
        }
        sort(tmp.begin(),tmp.end());
        ll ans=0;
        rep(j,ceil((double)tmp.size()/2)){
            ans+=tmp[j];
        }
        d[i]=ans;
        d.erase(d.begin()+i+1,d.begin()+r+1);
        
        /*rep(j,d.size()){
            if(d[j]>=0)cout<<d[j]<<" ";
            else cout<<"|";
        }
        cout<<endl;*/
    }
    cout<<d[0]<<endl;
    return true;
}

int main(){
    ll n;
    cin>>n;
    rep(i,n)solve();
    return 0;
}