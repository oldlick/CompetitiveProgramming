#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)n; ++i)
#define FOR(i,s,n) for(int i=s; i<(int)n; ++i)
using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll LINF = 1LL<<60;

/*
bool dfs(VV<pair<ll,pair<ll,ll>>> &dx,VV<pair<ll,pair<ll,ll>>> &dy,ll x,ll y,V<ll> &u){
    ll gx=dx.size(),gy=dy.size();
    for(auto &i:dx[x]){
        if(i.second.first<=y && y<=i.second.second)u[i.first]++;
    }
    for(auto &i:dy[y]){
        if(i.second.first<=x && x<=i.second.second)u[i.first]++;
    }
    dfs(dx,dy,x+1,y,u);
    dfs(dx,dy,x,y+1,u);
}*/

bool solve(){
    ll n;
    cin>>n;
    if(n==0)return false;
    ll sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;
    bool fx=false,fy=false;
    if(sx>gx){
        fx=true;
        gx=sx*2-gx;
    }
    if(sy>gy){
        fy=true;
        gy=sy*2-gy;
    }
    gx-=sx-1;gy-=sy-1;
    VV<pair<ll,pair<ll,ll>>> dx(gx),dy(gy);
    ll preans=0;
    REP(i,n){
        ll x,y,r;
        cin>>x>>y>>r;
        if(fx==true)x=sx*2-x;
        if(fy==true)y=sy*2-y;
        x-=sx-1;y-=sy-1;
        if(x-r<0 && 0<=x+r && y-r<0 && 0<=y+r)preans++;
        if(0<=x-r && x-r<gx)dx[x-r].push_back(make_pair(i,make_pair(y-r,y+r)));
        if(0<=y-r && y-r<gy)dy[y-r].push_back(make_pair(i,make_pair(x-r,x+r)));
    }/*
    for(auto &x:dx){
        for(auto &y:x){
            cout<<y.first<<" "<<flush;
            cout<<y.second.first<<" "<<flush;
            cout<<y.second.second<<endl;
        }
    }
    for(auto &x:dy){
        for(auto &y:x){
            cout<<y.first<<" "<<flush;
            cout<<y.second.first<<" "<<flush;
            cout<<y.second.second<<endl;
        }
    }*/
    cout<<"test"<<endl;
    ll ans=LINF;
    queue<pair<pair<ll,ll>,V<ll>>> q;
    q.push(make_pair(0,0));
    VV<V<ll>> du(gx,VV<ll>(gy,V<ll>(n,0)));
    VV<ll> still(gx,V<ll>(gy));
    while(q.size()){
        ll x=q.front().first,y=q.front().second;
        V<ll> u=du[x][y];
        q.pop();
        cout<<"OK"<<x<<" "<<y<<endl;
        ll tmp=0;
        REP(i,n)if(u[i]!=0)tmp++;
        if(x==gx-1 && y==gy-1){
            //cout<<"IN"<<endl;
            if(tmp<ans)ans=tmp;
            //cout<<"OUT"<<endl;
            continue;
        }
        //cout<<"TH"<<endl;
        //cout<<dx[x].size()<<endl;
        for(auto &i:dx[x]){
        //cout<<"CASE1 "<<flush<<i.second.first<<" "<<flush<<i.first<<endl;
            if(i.second.first<=y && y<=i.second.second)u[i.first]++;
        }
        for(auto &i:dy[y]){
        //cout<<"CASE2 "<<flush<<i.first<<endl;
            if(i.second.first<=x && x<=i.second.second)u[i.first]++;
        }
        //cout<<"TH2"<<endl;
        ll tmp2;
        tmp2=0;
        REP(i,n)if(du[x+1][y][i]!=0)tmp2++;
        if(tmp<tmp2)du[x+1][y]=u[x][y];
        if(x+1!=gx && still[x+1][y]==0){
            still[x+1][y]=1;
            q.push(make_pair(make_pair(x+1,y),u));
        }
        tmp2=0;
        REP(i,n)if(du[x][y+1][i]!=0)tmp2++;
        if(tmp<tmp2)du[x][y+1]=u[x][y];
        if(y+1!=gy && still[x][y+1]==0){
            still[x][y+1]=1;
            q.push(make_pair(make_pair(x,y+1),u));
        }
    }
    cout<<ans+preans<<endl;
    return true;
}

int main(){
    while(solve());
}