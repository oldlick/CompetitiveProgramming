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

int main(){
  init();
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand100(0, 99);
  inl(a,b);
  VV<ll> t(50,V<ll>(50));
  rep(i,50)rep(j,50){
    in(t[i][j]);
  }
  VV<ll> p(50,V<ll>(50));
  rep(i,50)rep(j,50){
    in(p[i][j]);
  }
  ll dx[4]={1,0,-1,0};
  ll dy[4]={0,1,0,-1};
  VV<V<ll>> priority(50,VV<ll>(50,V<ll>(5)));//p[i][j][k]:k0-3 next dir / k=4 first dir
  rep(i,50)rep(j,50){
    V<pair<ll,ll>> tmp(4);
    rep(k,4){
      ll nextX=i+dx[k];
      ll nextY=j+dy[k];
      if(nextX<0 || nextY<0 || nextX>=50 || nextY>=50)continue;
      tmp[k]={-k,k};
    }
    sort(all(tmp));
    rep(k,3)priority[i][j][tmp[k].se]=tmp[k+1].se;
    priority[i][j][tmp[3].se]=-1;
    priority[i][j][4]=tmp[0].se;
  }
  ll mxV=0;
  V<ll> mxA;
  ll nwV=0;
  V<ll> nwA;
  ll nwX=a;
  ll nwY=b;
  V<ll> nwL(50*50);
  nwV+=p[nwX][nwY];
  nwL[t[nwX][nwY]]=1;
  ll dirOld=4;
  rep(i,174520069){
    ll dir=-1;
    ll nextX,nextY;
    while(priority[nwX][nwY][dirOld]!=-1){
      dirOld=priority[nwX][nwY][dirOld];
      nextX=nwX+dx[dirOld];
      nextY=nwY+dy[dirOld];
      if(nextX<0 || nextY<0 || nextX>=50 || nextY>=50)continue;
      if(nwL[t[nextX][nextY]]==0){
        dir=dirOld;
        break;
      }
    }
    //out(next);
    if(dir==-1){
      if(nwA.size()==0)break;
      nwV-=p[nwX][nwY];
      nwL[t[nwX][nwY]]=0;
      dirOld=nwA.back();
      nwA.pop_back();
      nwX-=dx[(dirOld+4)%4];
      nwY-=dy[(dirOld+4)%4];
    }else{
      nwX=nextX;
      nwY=nextY;
      nwV+=p[nwX][nwY];
      nwL[t[nwX][nwY]]=1;
      nwA.push_back(dir);
      if(chmax(mxV,nwV)){
        mxA=nwA;
      }
      dirOld=4;
    }
  }
  each(x,mxA){
    if(x==0)cout<<"D";
    if(x==1)cout<<"R";
    if(x==2)cout<<"U";
    if(x==3)cout<<"L";
  }
  cout<<endl;
  return 0;
}