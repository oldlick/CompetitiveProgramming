#include <iostream>
#include <vector>

using namespace std;
using ll= long long;

bool cut(vector<vector<ll>> &d,ll j,ll &ans){
    bool f=false;
    ll prev=-1;
    for(ll i=0;i<5;i++){
        if(i+1<d.size() && d[i][j]==d[i+1][j])continue;
        if(i-prev>=3 && d[i][j]!=0){
            ans+=(i-prev)*d[i][j];
            f=true;
            for(ll k=prev+1;k<=i;k++){
                d[k].erase(d[k].begin()+j);
                d[k].push_back(0);
            }
        }
        prev=i;
    }
    return f;
}

bool solve(){
    ll h;
    cin>>h;
    if(h==0)return false;
    vector<vector<ll>> d(5,vector<ll>(h));
    for(ll j=h-1;j>=0;j--){
        for(ll i=0;i<5;i++){
            ll tmp;
            cin>>tmp;
            d[i][j]=tmp;
        }
    }
    ll ans=0;
    bool f;
    do{
        f=false;
        for(ll j=h-1;j>=0;j--){
            f|=cut(d,j,ans);
        }/*
        for(ll j=h-1;j>=0;j--){
            for(ll i=0;i<5;i++){
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"["<<ans<<"]"<<endl;*/
    }while(f==true);
    cout<<ans<<endl;
    return true;
}
int main(){
    while(solve());
}
