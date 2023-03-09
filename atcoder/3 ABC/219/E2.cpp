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

/*bool check(ll bit){
  ll dx[4]={1,-1,0,0};
  ll dy[4]={0,0,1,-1};
  bool fAll;
  rep(i,4)rep(j,4){
    bool f;
    rep(d,4){
      ll i_=i+dx[d],j_=j+dy[d];
      if(i_<0||j_<0||i_>=4||j_>=4)continue;
      if(((bit>>(i_*4+j_))&1)==1)g.push_back(i*4+j)
    }
    if(f==false)fAll=false;
  }
  return fAll;
}*/

bool check2(ll bit){
  VV<ll> c(4,V<ll>(4,-1));
  ll dx[4]={1,-1,0,0};
  ll dy[4]={0,0,1,-1};
  ll num=0;
  rep(i,4){
    rep(j,4){
      if(((bit>>(i*4+j))&1)==1)c[i][j]=num++;
    }
  }
  rep(loop,16){
    rep(i,4)rep(j,4){
      if(c[i][j]==-1)continue;
      rep(d,4){
        ll i_=i+dx[d],j_=j+dy[d];
        if(i_<0||j_<0||i_>=4||j_>=4)continue;
        if(c[i_][j_]==-1)continue;
        chmin(c[i_][j_],c[i][j]);
      }
    }
  }
  rep(i,4)rep(j,4)if(c[i][j]!=0&&c[i][j]!=-1)return false;
  
  VV<ll> dc(6,V<ll>(6,-1));
  num=1;
  rep(i,4){
    rep(j,4){
      if(((bit>>(i*4+j))&1)==0)dc[i+1][j+1]=num++;
    }
  }
  rep(i,6){
    dc[i][0]=0;
    dc[i][5]=0;
  }
  rep(i,6){
    dc[0][i]=0;
    dc[5][i]=0;
  }
  rep(loop,25){
    rep(i,6)rep(j,6){
      if(dc[i][j]==-1)continue;
      rep(d,4){
        ll i_=i+dx[d],j_=j+dy[d];
        if(i_<0||j_<0||i_>=6||j_>=6)continue;
        if(dc[i_][j_]==-1)continue;
        chmin(dc[i_][j_],dc[i][j]);
      }
    }
  }
  rep(i,4)rep(j,4)if(dc[i][j]!=0&&dc[i][j]!=-1)return false;

  return true;
}

bool hoge(ll bit){
  VV<ll> c(4,V<ll>(4,-1));
  ll dx[4]={1,-1,0,0};
  ll dy[4]={0,0,1,-1};
  ll num=0;
  rep(i,4){
    rep(j,4){
      if(((bit>>(i*4+j))&1)==1)c[3-i][3-j]=num++;
    }
  }
  rep(i,4){
    rep(j,4){
      if(c[i][j]!=-1)cout<<"#";
      else cout<<".";
    }
    cout<<endl;
  }
  cout<<endl;
}

int main(){
  init();
  ll a=0;
  rep(i,4)rep(j,4){
    inl(tmp);
    a<<=1;
    a+=tmp;
  }
  ll ans=0;
  rep(bit,1<<16){
    if((~bit&a)!=0)continue;
    if(check2(bit)){
      //hoge(bit);
      ans++;
    }
  }
  out(ans);
  return 0;
}