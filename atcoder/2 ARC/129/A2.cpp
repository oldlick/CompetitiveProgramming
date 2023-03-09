// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : A.cpp
// Version  : ver 1.0
// Date     : 2021-11-21 Sun 20:51:02
// -------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
using ll = long long;
using ld = long double;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
#define each(x,v) for(auto& x : (v))
#define reps(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define fi first
#define se second
const ll INF = 1LL << 60;
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) ((a)<=(x)&&(x)<=(b))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define debug cout << "line : " << __LINE__ << " debug" << endl;
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) long double __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
void in(){}
template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
template <typename T> void in1(T &s) {rep(i,s.size()){in(s[i]);}}
template <typename T> void in2(T &s,T &t) {rep(i,s.size()){in(s[i],t[i]);}}
void out(){cout << endl;}
template <typename T,class... U> void out(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; out(u...);}
void die(){cout << endl;exit(0);}
template <typename T,class... U> void die(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; die(u...);}
template <typename T> void outv(T s) {rep(i,s.size()){if(i!=0)cout<<" ";cout<<s[i];}cout<<endl;}
template <typename T> void out1(T s) {rep(i,s.size()){out(s[i]);}}
template <typename T> void out2(T s,T t) {rep(i,s.size()){out(s[i],t[i]);}}
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

int main(){
  init();
  /*
  rep(n_bit,2)rep(r_bit,2)rep(l_bit,2)rep(x,2)rep(nf,2)rep(rf,2)rep(lf,2){
    ll nf_=nf,rf_=rf,lf_=lf;
    if(x==0 && l_bit==1 && lf==1)continue;
    if(x==1 && l_bit==0)lf_=0;
    if(x==1 && r_bit==0 && rf==1)continue;
    if(x==0 && r_bit==1)rf_=0;
    if(x==1 && n_bit==0 && nf==1)continue;
    if(x==1 && n_bit==1)nf_=0;

    out(n_bit,r_bit,l_bit,x,":",nf_,rf_,lf,"->",nf,rf,lf);
  }
  return 0;
  */
  inl(n,l,r);
  V<ll> cnt(8);
  cnt[1*4+1*2+1]=1;
  rep(i,60){
    int n_bit = (n>>(59-i))&1;
    int r_bit = (r>>(59-i))&1;
    int l_bit = (l>>(59-i))&1;
    V<ll> cnt2(8);
    rep(nf,2)rep(rf,2)rep(lf,2)rep(x,2){
      ll nf_=nf,rf_=rf,lf_=lf;
      if(x==0 && l_bit==1 && lf==1)continue;
      if(x==1 && l_bit==0)lf_=0;
      if(x==1 && r_bit==0 && rf==1)continue;
      if(x==0 && r_bit==1)rf_=0;
      if(x==1 && n_bit==0 && nf==1)continue;
      if(x==1 && n_bit==1)nf_=0;

      cnt2[nf_*4+rf_*2+lf_]+=cnt[nf*4+rf*2+lf];
    }
    cnt.swap(cnt2);
    //outv(cnt);
  }
  ll ans=0;
  rep(rf,2)rep(lf,2){
    ans+=cnt[rf*2+lf];
  }
  out(ans);
  return 0;
}