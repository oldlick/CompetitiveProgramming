#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define reps(i,n) for(int i=s;i<(int)n;++i)

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

bool solve(){
    string s;
    getline(cin,s);
    if(s==".")return false;
    deque<ll> q;
    rep(i,s.size()){
        if(s[i]=='[')q.push_back(1);
        if(s[i]=='(')q.push_back(2);
        if(s[i]==']'){
            if(q.size()==0){
                cout<<"no"<<endl;
                return true;
            }
            if(q.back()!=1){
                cout<<"no"<<endl;
                return true;
            }
            q.pop_back();
        }
        if(s[i]==')'){
            if(q.size()==0){
                cout<<"no"<<endl;
                return true;
            }
            if(q.back()!=2){
                cout<<"no"<<endl;
                return true;
            }
            q.pop_back();
        }
    }
    if(q.size()==0)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return true;
}


int main(){
    while(solve());
    return 0;
}