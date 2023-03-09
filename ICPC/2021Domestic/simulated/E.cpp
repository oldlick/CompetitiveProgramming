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


// 1-indexed
struct BIT {
private:
  vector<int> bit;
  int N;

public:
  BIT(int size) {
    N = size;
    bit.resize(N + 1);
  }

  // 一点更新です
  void add(int a, int w) {
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
  }

  // 1~Nまでの和を求める。
  int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
};

struct TREE{
  int N,node[400010],lazy[400010];
  bool flag[400010];
  void init(int N_){
      N=1;
      while(N<N_)N*=2;
      rep(i,2*N-1){
          node[i]=((int)1<<31)-1;
          flag[i]=false;
      }
  }
  void eval(int k,int l,int r){
      if(flag[k]){
          node[k]=lazy[k];
          if(l+1<r){
              lazy[2*k+1]=lazy[2*k+2]=lazy[k];
              flag[2*k+1]=flag[2*k+2]=true;
          }
          flag[k]=false;
      }
  }
  void update(int a,int b,int x,int k=0,int l=0,int r=N){
      eval(k,l,r);
      if(r<=a||b<=l)return;
      if(a<=l&&r<=b){
          flag[k]=true;
          lazy[k]=x;
          eval(k,l,r);
      }
      else{
          update(a,b,x,2*k+1,l,(l+r)/2);
          update(a,b,x,2*k+2,(l+r)/2,r);
          node[k]=min(node[2*k+1],node[2*k+2]);
      }
  }
  int query(int a,int b,int k=0,int l=0,int r=N){
      eval(k,l,r);
      if(r<=a||b<=l)return INF;
      if(a<=l&&r<=b)return node[k];
      int vl=query(a,b,2*k+1,l,(l+r)/2);
      int vr=query(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
  }
}

bool solve(){
  inl(n);
  if(n==0)return false;
  V<ll> p(n);
  in1(p);
  ll ans=INF;
  V<ll> v;
  {
    BIT bit(n);
    rep(i,n){
      v.push_back(i-bit.sum(p[i]));
      bit.add(p[i],1);
    }
  }
  /*
  {
    BIT bit(n);
    reverse(all(p));
    rep(i,n){
      v.push_back(bit.sum(p[i]));
      bit.add(p[i],1);
    }
  }
  */
  //
  sort(all(v));
  deque<ll> q;
  rep(i,n)q.push_back(v[i]);
  ll mn=0,ans=0;
  while(q.size()!=0){
    while(q.size()!=0){
      if(q.front()<=mn)q.pop_front();
      else break;
    }
    ll mn=q.front(),mx=q.back(),sz=q.size();
    ll mx_del=(mx+1)+mn*sz
    if()
  }

  out(ans);
  return true;
}

int main(){
  init();
  while(solve());
  return 0;
}