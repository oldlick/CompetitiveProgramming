// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : E.cpp
// Version  : ver 1.0
// Date     : 2021-11-20 Sat 20:25:09
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

const int mod1 = 998244353;
class mint1 {
public:
  long long x;
  mint1(long long x=0) : x((x%mod1+mod1)%mod1) {}
  mint1 operator-() const { 
    return mint1(-x);
  }
  mint1& operator+=(const mint1& a) {
    if ((x += a.x) >= mod1) x -= mod1;
    return *this;
  }
  mint1& operator-=(const mint1& a) {
    if ((x += mod1-a.x) >= mod1) x -= mod1;
    return *this;
  }
  mint1& operator*=(const  mint1& a) {
    (x *= a.x) %= mod1;
    return *this;
  }
  mint1 operator+(const mint1& a) const {
    mint1 res(*this);
    return res+=a;
  }
  mint1 operator-(const mint1& a) const {
    mint1 res(*this);
    return res-=a;
  }
  mint1 operator*(const mint1& a) const {
    mint1 res(*this);
    return res*=a;
  }
  mint1 pow(long long t) const {
    if (!t) return 1;
    mint1 a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod1
  mint1 inv() const {
    return pow(mod1-2);
  }
  mint1& operator/=(const mint1& a) {
    return (*this) *= a.inv();
  }
  mint1 operator/(const mint1& a) const {
    mint1 res(*this);
    return res/=a;
  }
  friend ostream& operator<<(ostream& os, const mint1& m){
    os << m.x;
    return os;
  }
};

const int mod = 998244352;
class mint {
public:
  long long x;
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

int main(){
  init();
  inl(n,k,m);
  mint p=((mint)k).pow(n);
  mint1 ans=((mint1)m).pow(p.x);
  out(ans);
  return 0;
}
//100 123 345
//2 3 2
//100 123 1
//1000000000000000000 1000000000000000000 1000000000000000000
//101 230 1000000000000000000
//100 123 998244353
//100 123 1996488708
//1 1 1000000000000000000
//12 123 998244353
//1000000000000000000 1000000000000000000 998244353
//1 1 998244353