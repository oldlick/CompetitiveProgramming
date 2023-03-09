//ver 8.1
#include <bits/stdc++.h>
using namespace std;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<string>;
using vb = vector<bool>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<ld>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;
using pll = pair<ll,ll>;
using mll = map<ll,ll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
#define each(x,v) for(auto& x : (v))
#define reps(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
const ll INF = 1LL << 60;
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) ((a)<=(x)&&(x)<=(b))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define debug cout << "line : " << __LINE__ << " debug" << endl;
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) long double __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
void in(){}
template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
template <typename T> void in1(T &s) {rep(i,s.size()){in(s[i]);}}
template <typename T> void in2(T &s,T &t) {rep(i,s.size()){in(s[i],t[i]);}}
template <typename T> void in3(T &s,T &t,T &u) {rep(i,s.size()){in(s[i],t[i],u[i]);}}
template <typename T> void in4(T &s,T &t,T &u,T &v) {rep(i,s.size()){in(s[i],t[i],u[i],v[i]);}}
template <typename T> void in5(T &s,T &t,T &u,T &v,T &w) {rep(i,s.size()){in(s[i],t[i],u[i],v[i],w[i]);}}
void out(){cout << endl;}
template <typename T,class... U> void out(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; out(u...);}
void die(){cout << endl;exit(0);}
template <typename T,class... U> void die(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; die(u...);}
template <typename T> void outv(T s) {rep(i,s.size()){if(i!=0)cout<<" ";cout<<s[i];}cout<<endl;}
template <typename T> void out1(T s) {rep(i,s.size()){out(s[i]);}}
template <typename T> void out2(T s,T t) {rep(i,s.size()){out(s[i],t[i]);}}
template <typename T> void out3(T s,T t,T u) {rep(i,s.size()){out(s[i],t[i],u[i]);}}
template <typename T> void out4(T s,T t,T u,T v) {rep(i,s.size()){out(s[i],t[i],u[i],v[i]);}}
template <typename T> void out5(T s,T t,T u,T v,T w) {rep(i,s.size()){out(s[i],t[i],u[i],v[i],w[i]);}}
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
template <typename T> T allSum(vector<T> a){T ans=T();each(it,a)ans+=it;return ans;}
template<typename T> bool inside(T a,T b){auto it=a.begin()-1;each(x,b){it=find(it+1,a.end(),x);if(it==a.end())return false;}return true;}
ll ceilDiv(ll a,ll b) {return (a+b-1)/b;}
ld dist(pair<ld,ld> a, pair<ld,ld> b){return sqrt(abs(a.fi-b.fi)*abs(a.fi-b.fi)+abs(a.se-b.se)*abs(a.se-b.se));} // ２点間の距離 
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b;}
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )

ll k;
V<ll> ok;

template<class T>
tuple<V<T>,V<ll>> dijk1(VV<pair<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<T,ll>,vector<pair<T,ll>>,greater<pair<T,ll>>> q;
  q.push(mp(0,s));
  vector<T> cost(n,INF);
  vector<ll> pre(n,-1);
  cost[s]=0;
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second){
        cost[x.first]=cost[now.second]+x.second;
        pre[x.first]=now.second;
        q.push(mp(cost[x.first],x.first));
      }
    }
    //outv(cost);
  }
  //outv(cost);
  return {cost,pre};
}
template<class T>
tuple<V<T>,V<ll>> dijk2(VV<pair<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<T,ll>,vector<pair<T,ll>>,greater<pair<T,ll>>> q;
  q.push(mp(0,s));
  vector<T> cost(n,INF);
  vector<ll> pre(n,-1);
  cost[s]=0;
  rep(i,n)if(ok[i]==1){
    cost[i]=0;
    q.push(mp(0,i));
  }
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second){
        cost[x.first]=cost[now.second]+x.second;
        pre[x.first]=now.second;
        q.push(mp(cost[x.first],x.first));
      }
    }
    //outv(cost);
  }
  //outv(cost);
  return {cost,pre};
}

int main(){
  init();
  inl(h,w);
  in(k);
  ll n=h*w;
  V<string> m(h);
  rep(i,h)in(m[i]);
  VV<pair<ll,ll>> g1(n);
  VV<pair<ll,ll>> g2(n);
  ll s=0;
  reps(i,1,h-1)reps(j,1,w-1){
    ll a=i*w+j;
    ll d[4]={-1,w,1,-w};
    if(m[a/w][a%w]=='S')s=a;
    rep(k,4){
      ll b=a+d[k];
      ll c=1;
      if(m[a/w][a%w]=='#'||m[b/w][b%w]=='#')c=INF;
      g1[a].push_back(make_pair(b,c));
      g1[b].push_back(make_pair(a,c));
      g2[a].push_back(make_pair(b,1));
      g2[b].push_back(make_pair(a,1));
    }
  }
  {
    ok.resize(n);
    auto[cost,pre]=dijk1(g1,s);
    rep(i,n)if(cost[i]<=k)ok[i]=1;
    rep(i,h){
      rep(j,w){
        //cout<<cost[i*w+j]<<" ";
      }
      //out();
    }
  }
  {
    auto [cost,pre]=dijk2(g2,s);
    ll ans=INF;
    rep(i,h){
      rep(j,w){
        //cout<<cost[i*w+j]<<" ";
        if(i==0||i==h-1||j==0||j==w-1)chmin(ans,(cost[i*w+j]+k-1)/k);
      }
      //out();
    }
    out(ans+1);
  }
  return 0;
}
/*
11 9 1
#########
#########
#########
#########
#########
####S##..
#########
#########
#########
#########
#########
*/