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

const int mod = 998244353;
class mint {
  long long x;
public:
  mint(long long x=0) : x((x%mod+mod)%mod) {}
  mint operator-() const { 
    return mint(-x);
  }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const  mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint& a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint& a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint& a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint& a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint& a) const {
    mint res(*this);
    return res/=a;
  }
  friend ostream& operator<<(ostream& os, const mint& m){
    os << m.x;
    return os;
  }
};

void dfs(VV<ll> &g,ll now,V<ll> &seen,ll cost_,V<ll> &cost){
  seen[now]=1;
  cost[now]=cost_;
  each(x,g[now]){
    if(seen[x]==1)continue;
    dfs(g,x,seen,cost_+1,cost);
  }
}

int main(){
  init();
  inl(n);
  VV<ll> g(n);
  rep(i,n-1){
    inl(a,b);a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  V<ll> cost1(n);
  V<ll> seen1(n);
  dfs(g,0,seen1,0,cost1);
  ll p1=0;
  rep(i,n)if(cost1[p1]<cost1[i])p1=i;
  V<ll> cost2(n);
  V<ll> seen2(n);
  dfs(g,p1,seen2,0,cost2);
  ll p2=0;
  rep(i,n)if(cost2[p2]<cost2[i])p2=i;
  ll d=cost2[p2];
  V<ll> cost3(n);
  V<ll> seen3(n);
  dfs(g,p2,seen3,0,cost3);
  //out(d);
  if(d%2==0){
    ll pc=0;
    rep(i,n)if(cost3[i]==d/2&&cost2[i]==d/2)pc=i;
    //out(pc);
    V<ll> ls;
    each(x,g[pc]){
      V<ll> cost4(n);
      V<ll> seen4(n);
      each(y,g[pc])if(x!=y)seen4[y]=1;
      dfs(g,x,seen4,0,cost4);
      ll cnt=0;
      rep(i,n)if(cost4[i]==d/2)cnt++;
      ls.push_back(cnt);
    }
    //outv(ls);
    mint ans=0;
    ll m=ls.size();
    V<mint> sum(1);
    rep(i,m)sum.push_back(sum.back()+ls[i]);
    rep(i,m){
      ans+=sum[i]*ls[i]*(sum.back()-sum[i+1]+1);
    }
    out(ans);
  }else{
    V<ll> pc(2);
    rep(i,n){
      if(cost3[i]==d/2&&cost2[i]==d/2+1)pc[0]=i;
      if(cost3[i]==d/2+1&&cost2[i]==d/2)pc[1]=i;
    }
    V<mint> ls;
    rep(i,2){
      V<ll> cost4(n);
      V<ll> seen4(n);
      seen4[pc[(i+1)%2]]=1;
      dfs(g,pc[i],seen4,0,cost4);
      ll cnt=0;
      rep(i,n)if(cost4[i]==d/2)cnt++;
      ls.push_back(cnt);
    }
    out(ls[0]*ls[1]);
  }
  return 0;
}