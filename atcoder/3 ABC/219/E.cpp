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

VV<ll> a;
bool check(set<pair<pair<ll,ll>,pair<ll,ll>>> &usedPath,bool f=false){
  rep(i,4){
    bool f1=true;
    bool f2=false;
    rep(j,4){
      if(usedPath.count({{i,j},{i+1,j}})==1||usedPath.count({{i+1,j},{i,j}})==1)f2^=true;
      if(a[i][j]==1&&f2==false)f1=false;
      //if(f)cout<<f2<<" ";
    }
    //if(f)cout<<endl;
    if(f1==false)return false;
  }
  rep(j,4){
    bool f1=true;
    bool f2=false;
    rep(i,4){
      if(usedPath.count({{i,j},{i,j+1}})==1||usedPath.count({{i,j+1},{i,j}})==1)f2^=true;
      if(a[i][j]==1&&f2==false)f1=false;
    }
    if(f1==false)return false;
  }
  return true;
}

void hoge(set<pair<pair<ll,ll>,pair<ll,ll>>> &usedPath){
  VV<ll> b(9,V<ll> (9));
  each(x,usedPath){
    b[x.fi.fi+x.fi.fi][x.fi.se+x.fi.se]=1;
    b[x.fi.fi+x.se.fi][x.fi.se+x.se.se]=1;
    b[x.se.fi+x.se.fi][x.fi.se+x.se.se]=1;
  }
  rep(i,9){
    rep(j,9){
      if(b[i][j]==1)cout<<'#';
      else cout<<'.';
    }
    cout<<endl;
  }
  cout<<endl;
}

ll ans;
void dfs(set<pair<pair<ll,ll>,pair<ll,ll>>> &usedPath,set<pair<ll,ll>> &usedNode,pair<ll,ll> now){
  //out(now.fi,now.se);
  if(now==mp(0LL,0LL)&&usedNode.size()!=0){
    if(check(usedPath)){
      ans++;
      //each(x,usedPath)cout<<"("<<x.fi.fi<<"/"<<x.fi.se<<")("<<x.se.fi<<"/"<<x.se.se<<") "<<endl;
      //cout<<endl;
      //each(x,usedNode)cout<<x.fi<<"/"<<x.se<<" ";
      //cout<<endl;
      //check(usedPath,true);
      hoge(usedPath);
      //die();
    }
    return;
  }
  ll dx[4]={1,-1,0,0};
  ll dy[4]={0,0,1,-1};
  rep(d,4){
    auto nxt=now;
    nxt.fi+=dx[d];
    nxt.se+=dy[d];
    if(nxt.fi<0||nxt.se<0||nxt.fi>4||nxt.se>4)continue;
    if(usedPath.count({now,nxt})==1||usedPath.count({nxt,now})==1)continue;
    if(usedNode.count(nxt)==1)continue;
    usedPath.insert({now,nxt});
    usedNode.insert(nxt);
    dfs(usedPath,usedNode,nxt);
    usedPath.erase({now,nxt});
    usedNode.erase(nxt);
  }
}

int main(){
  init();
  a.resize(4);
  rep(i,4){
    a[i].resize(4);
    in1(a[i]);
  }
  set<pair<pair<ll,ll>,pair<ll,ll>>> usedPath;
  set<pair<ll,ll>> usedNode;
  pair<ll,ll> now={0,0};
  dfs(usedPath,usedNode,now);
  out(ans/2);
  return 0;
}

0 1 0 0
1 1 1 1
1 1 1 1
1 1 1 1