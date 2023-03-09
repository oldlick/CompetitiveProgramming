/*ver 7*/
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
#define each(x,v) for(auto& x : v)
#define reps(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
const ll INF = 1LL << 60;
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<=b)
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
ll ceilDiv(ll a,ll b) {return (a+b-1)/b;}
ld dist(pair<ld,ld> a, pair<ld,ld> b){return sqrt(abs(a.fi-b.fi)*abs(a.fi-b.fi)+abs(a.se-b.se)*abs(a.se-b.se));} // ２点間の距離 
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b;}
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )

VV<ll> d;
ll n;
template <typename T> bool isOk(T key){
  V<ll> use(5);
  rep(i,3){
    ll maxId=0;
    ll maxVa=-INF;
    ll minLe=INF;
    ll minL=INF;
    rep(j,n){
      ll tmpVa=0;
      ll tmpLe=INF;
      ll tmpML=-INF;
      ll tmpnL=INF;
      rep(k,5){
        if(use[k]==1)continue;
        if(d[j][k]>=key){
          chmin(tmpLe,k);
          chmin(tmpnL,k);
          chmax(tmpML,k);
          tmpVa++;
        }
      }
      if(maxVa<tmpVa){
        maxVa=tmpVa;
        minLe=tmpLe;
        minL=tmpML-tmpnL;
        maxId=j;
      }else if(maxVa==tmpVa){
        if(minLe>tmpLe){
          maxVa=tmpVa;
          minLe=tmpLe;
          minL=tmpML-tmpnL;
          maxId=j;
        }else if(minLe==tmpLe){
          if(minL>tmpML-tmpnL){
            maxVa=tmpVa;
            minLe=tmpLe;
            minL=tmpML-tmpnL;
            maxId=j;
          }
        }
      }
    }
    rep(k,5){
      if(use[k]==1)continue;
      if(d[maxId][k]>=key)use[k]=1;
    }
    //out(key,maxId,maxVa);
  }
  ll cnt=0;
  rep(i,5)if(use[i]==1)cnt++;
  if(cnt==5)return true;
  return false;
}

int main(){
  init();
  in(n);
  d.resize(n,V<ll>(5));
  rep(i,n){
    in1(d[i]);
  }
  ll ok=-1;
  ll ng=1e9+1;

  while(abs(ok-ng)>1){
      ll mid=(ok+ng)/2;
      if(isOk(mid))ok=mid;
      else ng=mid;
  }
  out(ok);
  return 0;
}
/*
19
275 994 912 232 296 
393 7 85 958 315 
108 444 305 86 582 
942 676 979 86 631 
997 924 156 812 518 
28 949 580 555 576 
448 830 922 360 63 
218 105 422 304 63 
737 764 859 42 202 
794 336 230 773 775 
213 122 699 370 286 
569 398 236 149 305 
164 597 488 86 309 
903 305 766 677 961 
181 414 77 41 808 
279 187 496 861 312 
271 74 434 322 444 
73 892 194 661 393 
852 825 991 692 911 
*/