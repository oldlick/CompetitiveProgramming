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
tuple<V<T>,VV<ll>> dijk(VV<pair<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<T,ll>,vector<pair<T,ll>>,greater<pair<T,ll>>> q;
  q.push(mp(0,s));
  vector<T> cost(n,INF);
  vector<V<ll>> pre(n,V<ll>(1,-1));
  cost[s]=0;
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second){
        cost[x.first]=cost[now.second]+x.second;
        pre[x.first].clear();
        pre[x.first].push_back(now.second);
        q.push(mp(cost[x.first],x.first));
      }else if(cost[x.first]==cost[now.second]+x.second){
        pre[x.first].push_back(now.second);
      }
    }
    //outv(cost);
  }
  //outv(cost);
  return {cost,pre};
}

int main(){
  init();
  inl(n,m);
  VV<ll> d(n,V<ll>(n,INF));
  VV<pair<ll,ll>> g(n);
  map<pair<ll,ll>,ll> table;
  rep(i,m){
    inl(s,t);s--;t--;
    d[s][t]=1;
    g[s].push_back(make_pair(t,1));
    table[{s,t}]=i;
  }
  auto d1=d;
  VV<ll> d2(n,V<ll>(n,INF));
  
  rep(k,n)rep(i,n)rep(j,n){
    if(i==j||i==k||j==k)continue;
    //out(k,i,j,":",d1[i][k]+d1[k][j],d1[i][j],d2[i][j]);
    if(d1[i][k]+d1[k][j]<d1[i][j]){
      d2[i][j]=d1[i][j];
      //out("d2=",d1[i][j]);
      d1[i][j]=d1[i][k]+d1[k][j];
      //out("d1=",d1[i][k]+d1[k][j]);
    }else if(d1[i][k]+d1[k][j]<d2[i][j]){
      //out("d2=",d1[i][k]+d1[k][j]);
      d2[i][j]=d1[i][k]+d1[k][j];
    }
  }
  /*
  rep(i,n)outv(d1[i]);
  out();
  rep(i,n)outv(d2[i]);
  out();
  */
  auto [cost,pre]=dijk(g,0);
  if(cost[n-1]==INF){
    rep(i,m)out(-1);
    die();
  }
  ll now=n-1;
  V<pair<ll,ll>> ls;
  VV<ll> rev(n);
  rep(i,pre.size())each(x,pre[i])if(x!=-1)rev[x].push_back(i);
  while(pre[now].back()!=-1){
    if(pre[now].size()!=1)break;
    ls.push_back({pre[now].back(),now});
    now=pre[now].back();
  }
  now=0;
  while(rev[now].back()!=-1){
    if(rev[now].size()!=1)break;
    ls.push_back({now,rev[now].back()});
    now=rev[now].back();
  }
  V<ll> ans(m,INF);
  each(x,ls){
    if(d2[x.fi][x.se]==INF){
      ans[table[x]]=-1;  
    }else{
      ans[table[x]]=cost[n-1]+d2[x.fi][x.se]-d1[x.fi][x.se];
    }
  }
  rep(i,m)if(ans[i]==INF)ans[i]=cost[n-1];
  out1(ans);
  return 0;
}
