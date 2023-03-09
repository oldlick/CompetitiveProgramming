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

random_device rnd;
mt19937 mt(rnd());
ll dice(ll a,ll b){
  uniform_int_distribution<> r(a,b);
  return r(mt);
}

template<class T>
tuple<V<ll>,V<ll>> dijk(V<map<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push(mp(0,s));
  vector<ll> cost(n,INF);
  vector<ll> pre(n,-1);
  cost[s]=0;
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second){
        cost[x.first]=cost[now.second]+x.second;
        pre[x.first]=now.second;
        q.push(mp(cost[x.first],x.first));
      }
    }
    //outv(cost);
  }
  //outv(cost);
  return {cost,pre};
}

int main(){
  init();
  ll D=dice(100,2000);
  ll M=dice(1,2);
  V<map<ll,ll>> g(900);
  rep(i,30){
    ll x=dice(1,28);
    V<ll> H(2);
    rep(mode,2)H[mode]=dice(1000+D,9000-D);
    if(M==1)H[1]=H[0];
    rep(j,29){
      ll d=dice(-D,D);
      ll h=H[(j<x)]+d;
      g[i*30+j][i*30+j+1]=h;
      g[i*30+j+1][i*30+j]=h;
    }
  }
  rep(i,30){
    ll x=dice(1,28);
    V<ll> H(2);
    rep(mode,2)H[mode]=dice(1000+D,9000-D);
    if(M==1)H[1]=H[0];
    rep(j,29){
      ll d=dice(-D,D);
      ll h=H[(j<x)]+d;
      g[j*30+i][j*30+i+30]=h;
      g[j*30+i+30][j*30+i]=h;
    }
  }
  rep(i,30)rep(j,29){
    cout<<g[i*30+j][i*30+j+1];
    if(j==28)cout<<endl;
    else cout<<" ";
  }
  rep(i,29)rep(j,30){
    cout<<g[i*30+j][i*30+j+30];
    if(j==29)cout<<endl;
    else cout<<" ";
  }
  rep(i,1000){
    ll s1,s2,t1,t2;
    do{
      s1=dice(0,29);
      s2=dice(0,29);
      t1=dice(0,29);
      t2=dice(0,29);
    }while(abs(s1-t1)+abs(s2-t2)<10);
    auto [cost,path]=dijk(g,s1*30+s2);
    uniform_real_distribution<> realrand(0.9,1.1);
    ld e=realrand(mt);
    out(s1,s2,t1,t2,cost[t1*30+t2],e);
  }
  return 0;
}