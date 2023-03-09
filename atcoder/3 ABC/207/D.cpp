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
ll dist2(pair<ll,ll> a, pair<ll,ll> b){return abs(a.fi-b.fi)*abs(a.fi-b.fi)+abs(a.se-b.se)*abs(a.se-b.se);} // ２点間の距離 
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
  V<pair<ll,ll>> x(n),y(n);
  rep(i,n){
    inl(a,b);
    x[i].fi=a;
    x[i].se=b;
  }
  rep(i,n){
    inl(c,d);
    y[i].fi=c;
    y[i].se=d;
  }
  {
    /*ll i=1;
    ll j=0;
    sort(all(x),[&](const auto& lh, const auto& rh) {
      if(lh.se*j+lh.fi*i == rh.se*j+rh.fi*i){
        return lh.se*i-lh.fi*j > rh.se*i-rh.fi*j;
      }
      return lh.se*j+lh.fi*i > rh.se*j+rh.fi*i;
    });*/
    sort(all(x));
  }/*
  VV<ll> disX(n,V<ll>(n,INF));
  rep(i,n)rep(j,n){
    disX[i][j]=dist2(x[i],x[j]);
    //out("x",i,j,disX[i][j]);
  }*/
  reps(i,-10,11)reps(j,-10,11){
    //i=1;j=0;
    if(i==0&&j==0){
      /*if(i!=1&&j!=1&&i!=-1&&j!=-1){
        continue;
      }*/
      continue;
    }
    V<pair<ll,ll>> y_(n);
    rep(k,n){
      y_[k].fi=y[k].se*j+y[k].fi*i;
      y_[k].se=y[k].se*i-y[k].fi*j;
      //out(y[k].fi,y[k].se,y_[k].fi,y_[k].se);
    }
    /*sort(all(y_),[&](const auto& lh, const auto& rh) {
      if(lh.se*j+lh.fi*i == rh.se*j+rh.fi*i){
        return lh.se*i-lh.fi*j > rh.se*i-rh.fi*j;
      }
      return lh.se*j+lh.fi*i > rh.se*j+rh.fi*i;
    });*/
    sort(all(y_));
    bool f=true;
    /*
    rep(k,n)rep(l,n){
      //out("y",i,j,dist(y[i],y[j]));
      if(disX[k][l]*(i*i+j*j)!=dist2(y_[k],y_[l])){
        f=false;
        break;
      }
    }
    */
    rep(k,n){
      //out("y",i,j,dist(y[i],y[j]));
      ll dx_fi=(x[k].fi-x[0].fi);
      ll dy_fi=(y_[k].fi-y_[0].fi);
      if(dx_fi*dy_fi<0){
        f=false;
        break;
      }
      dx_fi=dx_fi*dx_fi*(i*i+j*j);
      dy_fi=dy_fi*dy_fi;
      //out(dx_fi,dy_fi);
      if(dx_fi!=dy_fi){
        f=false;
        break;
      }
      ll dx_se=(x[k].se-x[0].se);
      ll dy_se=(y_[k].se-y_[0].se);
      if(dx_se*dy_se<0){
        f=false;
        break;
      }
      dx_se=dx_se*dx_se*(i*i+j*j);
      dy_se=dy_se*dy_se;
      if(dx_se!=dy_se){
        f=false;
        break;
      }
    }
    //out("---");
    if(f)die("Yes");
  }
  out("No");
  return 0;
}