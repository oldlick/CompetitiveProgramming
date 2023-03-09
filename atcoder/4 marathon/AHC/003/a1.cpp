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
#ifndef ONLINE_JUDGE
  VV<ll> hc(30,V<ll>(29));
  VV<ll> vc(29,V<ll>(30));
  rep(i,30)rep(j,29)in(hc[i][j]);
  rep(i,29)rep(j,30)in(vc[i][j]);
#endif
  V<pair<ld,ll>> v(30,{0,0});
  V<pair<ld,ll>> h(30,{0,0});
  rep(i,1000){
    V<ll> ans;
    inl(s1,s2,t1,t2);
    ll useH;
    if(s1<t1){
      useH=s1;
      reps(i,s1,t1+1)if(h[i].fi/(h[i].se==0?1:h[i].se)<h[useH].fi/(h[useH].se==0?1:h[useH].se)){
        useH=i;
      }
    }else{
      useH=t1;
      reps(i,t1,s1+1)if(h[i].fi/(h[i].se==0?1:h[i].se)<h[useH].fi/(h[useH].se==0?1:h[useH].se)){
        useH=i;
      }
    }
    //out(h[useH].fi/(h[useH].se==0?1:h[useH].se)-hc[useH][0]);
    if(s1<t1)rep(j,useH-s1)ans.push_back(3);
    else rep(j,s1-useH)ans.push_back(1);
    if(s2<t2)rep(j,t2-s2)ans.push_back(0);
    else rep(j,s2-t2)ans.push_back(2);
    if(s1<t1)rep(j,t1-useH)ans.push_back(3);
    else rep(j,useH-t1)ans.push_back(1);
    each(x,ans){
      if(x==0)cout<<'R';
      if(x==1)cout<<'U';
      if(x==2)cout<<'L';
      if(x==3)cout<<'D';
    }
    cout<<endl;
    ll b=0;
#ifndef ONLINE_JUDGE
    {
      inl(a);
      ind(e);
      ll n1=s1,n2=s2;
      each(x,ans){
        if(x==0)b+=hc[n1][n2++];
        if(x==1)b+=vc[--n1][n2];
        if(x==2)b+=hc[n1][--n2];
        if(x==3)b+=vc[n1++][n2];
      }
      if(n1!=t1||n2!=t2)die("NG",n1,n2,"->",t1,t2);
    }
#else
    in(b);
#endif
    {
      ld cost=b/ans.size();
      ll n1=s1,n2=s2;
      each(x,ans){
        if(x==0){
          h[n1].first+=cost;
          h[n1].second++;
          n2++;
        }else if(x==1){
          v[n2].first+=cost;
          v[n2].second++;
          n1--;
        }else if(x==2){
          h[n1].first+=cost;
          h[n1].second++;
          n2--;
        }else if(x==3){
          v[n2].first+=cost;
          v[n2].second++;
          n1++;
        }
      }
    }
  }
  return 0;
}