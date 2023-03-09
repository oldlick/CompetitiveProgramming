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

ll h,w;
V<string> s;
tuple<ll,VV<ll>> hoge(){
  VV<ll> v;
  V<string> t=s;
  ll ans=0;
  V<ll> cnt(h);
  rep(i,h){
    ll f=0;
    ll tmp=0;
    rep(j,w){
      if(t[i][j]=='R'){
        f++;
        tmp=j;
      }
    }
    if(f!=0){
      cnt[i]=f-1;
      ans+=w;
      if(f==1){
        v.push_back({0,i,tmp});
        t[i][tmp]='B';
      }
    }
  }
  ll line=ans/w;
  rep(i,w){
    bool f=false;
    rep(j,h){
      if(t[j][i]=='R'&&cnt[j]>0){
        cnt[j]--;
        ans+=h-line;
        t[j][i]='B';
        v.push_back({1,j,i});
        f=true;
        break;
      }
    }
    if(f==true){
      rep(j,h)t[j][i]='B';
    }
  }
  rep(i,h){
    ll f=0;
    rep(j,w){
      if(t[i][j]=='R'){
        t[i][j]='B';
        v.push_back({0,i,j});
        break;
      }
    }
    if(f!=0){
      cnt[i]=f-1;
      ans+=w;
    }
  }
  return {ans,v};
}

template<class U>void rot(vector<U> &a){
  int h=a.size(),w=a[0].size();
  vector<U> pre(w,U(h,0));
  swap(a,pre);
  rep(i,w)rep(j,h)a[i][j]=pre[h-1-j][i];
}

int main(){
  init();
  in(h,w);
  s.resize(h);
  rep(i,h)in(s[i]);
  auto [ans1,v1]=hoge();
  rot(s);
  //rep(i,w)outv(s[i]);
  swap(h,w);
  auto [ans2,v2]=hoge();
  if(ans1>=ans2){
    //out(ans1);
    out(v1.size());
    each(x,v1){
      //out("??");
      if(x[0]==0)cout<<"X ";
      else cout<<"Y ";
      out(x[1]+1,x[2]+1);
    }
  }else{
    //out(ans2);
    out(v2.size());
    each(x,v2){
      if(x[0]==0)cout<<"Y ";
      else cout<<"X ";
      out(w-1-x[2]+1,x[1]+1);
    }
  }
  return 0;
}
/*
3 4
RBRB
RBRB
BBBB
*/