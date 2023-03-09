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

int main(){
  init();
  inl(n);
  V<ll> x(n),y(n);
  in2(x,y);/*
  set<V<ll>> s;
  rep(i,n)rep(j,n){
    s.insert({max(abs(x[i]-x[j]),abs(y[i]-y[j])),i,j});
  }
  each(x,s){
    outv(x);
  }*/
  ll mnX=0,mxX=0,mnY=0,mxY=0;
  rep(i,n){
    if(x[mnX]>x[i])mnX=i;
    if(x[mxX]<x[i])mxX=i;
    if(y[mnY]>y[i])mnY=i;
    if(y[mxY]<y[i])mxY=i;
  }
  ll p1,p2;
  if(x[mxX]-x[mnX]<y[mxY]-y[mnY]){
    p1=mxY;
    p2=mnY;
  }else{
    p1=mxX;
    p2=mnX;
  }
  //out(p1,p2);
  ll ans=-INF;
  mnX=-1,mxX=-1,mnY=-1,mxY=-1;
  rep(i,n){
    if(i==p1)continue;
    if(mnX==-1||x[mnX]>x[i])mnX=i;
    if(mxX==-1||x[mxX]<x[i])mxX=i;
    if(mnY==-1||y[mnY]>y[i])mnY=i;
    if(mxY==-1||y[mxY]<y[i])mxY=i;
  }
  //out(mxX,mnX,mxY,mnY);
  chmax(ans,x[mxX]-x[mnX]);
  chmax(ans,y[mxY]-y[mnY]);
  mnX=-1,mxX=-1,mnY=-1,mxY=-1;
  rep(i,n){
    if(i==p2)continue;
    if(mnX==-1||x[mnX]>x[i])mnX=i;
    if(mxX==-1||x[mxX]<x[i])mxX=i;
    if(mnY==-1||y[mnY]>y[i])mnY=i;
    if(mxY==-1||y[mxY]<y[i])mxY=i;
  }
  chmax(ans,x[mxX]-x[mnX]);
  chmax(ans,y[mxY]-y[mnY]);
  out(ans);
  return 0;
}






/*
20
407 361
167 433
756 388
-551 -47
306 -471
36 928
338 -355
911 852
288 70
-961 -769
-668 -386
-690 -378
182 -609
-677 401
-458 -112
184 -131
-243 888
-163 471
-11 997
119 544
*/