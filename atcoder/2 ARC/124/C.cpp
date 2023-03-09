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
V<ll> gcd(V<ll> a, V<ll> b) {
  V<ll> ret(a.size());
  rep(i,a.size()){
    ret[i]=min(a[i],b[i]);
  }
  return ret;
}
ll lcm(V<ll> p,V<ll> a,V<ll> b){
  ll ret=1;
  rep(i,a.size()){
    rep(j,max(a[i],b[i])){
      ret*=p[i];
    }
  }
  return ret;
}
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )

int main(){
  init();
  inl(n);
  VV<ll> a(n);
  rep(i,n){
    inl(c,d);
    a[i]={c,d};
  }
  set<ll> p;
  rep(i,n)rep(j,2){
    ll tmp=a[i][j];
    for(ll x=2;x*x<=tmp;x++){
      if(tmp%x!=0)continue;
      p.insert(x);
      while(tmp%x==0)tmp/=x;
    }
    if(tmp!=1)p.insert(tmp);
  }
  V<ll> pList;
  each(x,p)pList.push_back(x);

  VV<V<ll>> cnt(n,VV<ll>(2,V<ll>(pList.size())));
  rep(i,n)rep(j,2){
    ll tmp=a[i][j];
    rep(k,pList.size()){
      ll x=pList[k];
      while(tmp%x==0){
        tmp/=x;
        cnt[i][j][k]++;
      }
    }
    outv(cnt[i][j]);
  }
  out();
  V<V<ll>> gc(2,V<ll>(pList.size(),INF));
  rep(i,n){
    VV<V<ll>> gc2(2,V<V<ll>>(2,V<ll>(pList.size(),INF)));
    rep(rev,2){
      rep(j,2){
        gc2[rev][j]=gcd(gc[j],cnt[i][j^rev]);
      }
    }
    if(lcm(pList,gc2[0][0],gc2[0][1])<lcm(pList,gc2[1][0],gc2[1][1])){
      gc[0].swap(gc2[1][0]);
      gc[1].swap(gc2[1][1]);
    }else{
      gc[0].swap(gc2[0][0]);
      gc[1].swap(gc2[0][1]);
    }
    outv(gc[0]);
    outv(gc[1]);
  }
  out(lcm(pList,gc[0],gc[1]));
  return 0;
}