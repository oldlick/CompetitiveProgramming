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

template<class T>
tuple<V<T>,V<ll>> dijk(VV<pair<ll,T>> &g,ll s){
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

int main(){
  init();
  inl(h,w);
  V<string> s(h);
  in1(s);
  VV<pair<ll,ll>> g(h*w);
  rep(i,h){
    rep(j,w){
      if(0<=i-3&&i-3<h&&0<=j-1&&j-1<w&&s[i-3][j-1]=='.')g[i*w+j].push_back({(i-3)*w+j-1,1});
      if(0<=i-3&&i-3<h&&0<=j+0&&j+0<w&&s[i-3][j+0]=='.')g[i*w+j].push_back({(i-3)*w+j+0,1});
      if(0<=i-3&&i-3<h&&0<=j+1&&j+1<w&&s[i-3][j+1]=='.')g[i*w+j].push_back({(i-3)*w+j+1,1});
      if(0<=i-2&&i-2<h&&0<=j-2&&j-2<w&&s[i-2][j-2]=='.')g[i*w+j].push_back({(i-2)*w+j-2,1});
      if(0<=i-2&&i-2<h&&0<=j-1&&j-1<w)g[i*w+j].push_back({(i-2)*w+j-1,1});
      if(0<=i-2&&i-2<h&&0<=j+0&&j+0<w)g[i*w+j].push_back({(i-2)*w+j+0,1});
      if(0<=i-2&&i-2<h&&0<=j+1&&j+1<w)g[i*w+j].push_back({(i-2)*w+j+1,1});
      if(0<=i-2&&i-2<h&&0<=j+2&&j+2<w&&s[i-2][j+2]=='.')g[i*w+j].push_back({(i-2)*w+j+2,1});
      if(0<=i-1&&i-1<h&&0<=j-3&&j-3<w&&s[i-1][j-3]=='.')g[i*w+j].push_back({(i-1)*w+j-3,1});
      if(0<=i-1&&i-1<h&&0<=j-2&&j-2<w)g[i*w+j].push_back({(i-1)*w+j-2,1});
      if(0<=i-1&&i-1<h&&0<=j-1&&j-1<w)g[i*w+j].push_back({(i-1)*w+j-1,1});
      if(0<=i-1&&i-1<h&&0<=j+0&&j+0<w){
        if(s[i-1][j+0]=='.')g[i*w+j].push_back({(i-1)*w+j+0,0});
        else g[i*w+j].push_back({(i-1)*w+j+0,1});
      }
      if(0<=i-1&&i-1<h&&0<=j+1&&j+1<w)g[i*w+j].push_back({(i-1)*w+j+1,1});
      if(0<=i-1&&i-1<h&&0<=j+2&&j+2<w)g[i*w+j].push_back({(i-1)*w+j+2,1});
      if(0<=i-1&&i-1<h&&0<=j+3&&j+3<w&&s[i-1][j+3]=='.')g[i*w+j].push_back({(i-1)*w+j+3,1});
      if(0<=i+0&&i+0<h&&0<=j-3&&j-3<w&&s[i+0][j-3]=='.')g[i*w+j].push_back({(i+0)*w+j-3,1});
      if(0<=i+0&&i+0<h&&0<=j-2&&j-2<w)g[i*w+j].push_back({(i+0)*w+j-2,1});
      if(0<=i+0&&i+0<h&&0<=j-1&&j-1<w){
        if(s[i+0][j-1]=='.')g[i*w+j].push_back({(i+0)*w+j-1,0});
        else g[i*w+j].push_back({(i+0)*w+j-1,1});
      }
      if(0<=i+0&&i+0<h&&0<=j+1&&j+1<w){
        if(s[i+0][j+1]=='.')g[i*w+j].push_back({(i+0)*w+j+1,0});
        else g[i*w+j].push_back({(i+0)*w+j+1,1});
      }
      if(0<=i+0&&i+0<h&&0<=j+2&&j+2<w)g[i*w+j].push_back({(i+0)*w+j+2,1});
      if(0<=i+0&&i+0<h&&0<=j+3&&j+3<w&&s[i+0][j+3]=='.')g[i*w+j].push_back({(i+0)*w+j+3,1});
      if(0<=i+1&&i+1<h&&0<=j-3&&j-3<w&&s[i+1][j-3]=='.')g[i*w+j].push_back({(i+1)*w+j-3,1});
      if(0<=i+1&&i+1<h&&0<=j-2&&j-2<w)g[i*w+j].push_back({(i+1)*w+j-2,1});
      if(0<=i+1&&i+1<h&&0<=j-1&&j-1<w)g[i*w+j].push_back({(i+1)*w+j-1,1});
      if(0<=i+1&&i+1<h&&0<=j+0&&j+0<w){
        if(s[i+1][j+0]=='.')g[i*w+j].push_back({(i+1)*w+j+0,0});
        else g[i*w+j].push_back({(i+1)*w+j+0,1});
      }
      if(0<=i+1&&i+1<h&&0<=j+1&&j+1<w)g[i*w+j].push_back({(i+1)*w+j+1,1});
      if(0<=i+1&&i+1<h&&0<=j+2&&j+2<w)g[i*w+j].push_back({(i+1)*w+j+2,1});
      if(0<=i+1&&i+1<h&&0<=j+3&&j+3<w&&s[i+1][j+3]=='.')g[i*w+j].push_back({(i+1)*w+j+3,1});
      if(0<=i+2&&i+2<h&&0<=j-2&&j-2<w&&s[i+2][j-2]=='.')g[i*w+j].push_back({(i+2)*w+j-2,1});
      if(0<=i+2&&i+2<h&&0<=j-1&&j-1<w)g[i*w+j].push_back({(i+2)*w+j-1,1});
      if(0<=i+2&&i+2<h&&0<=j+0&&j+0<w)g[i*w+j].push_back({(i+2)*w+j+0,1});
      if(0<=i+2&&i+2<h&&0<=j+1&&j+1<w)g[i*w+j].push_back({(i+2)*w+j+1,1});
      if(0<=i+2&&i+2<h&&0<=j+2&&j+2<w&&s[i+2][j+2]=='.')g[i*w+j].push_back({(i+2)*w+j+2,1});
      if(0<=i+3&&i+3<h&&0<=j-1&&j-1<w&&s[i+3][j-1]=='.')g[i*w+j].push_back({(i+3)*w+j-1,1});
      if(0<=i+3&&i+3<h&&0<=j+0&&j+0<w&&s[i+3][j+0]=='.')g[i*w+j].push_back({(i+3)*w+j+0,1});
      if(0<=i+3&&i+3<h&&0<=j+1&&j+1<w&&s[i+3][j+1]=='.')g[i*w+j].push_back({(i+3)*w+j+1,1});
    }
  }
  auto [cost,pre]=dijk(g,0);
  /*rep(i,h){
    rep(j,w)cout<<cost[i*w+j];
    cout<<endl;
  }*/
  out(cost[h*w-1]);
  return 0;
}