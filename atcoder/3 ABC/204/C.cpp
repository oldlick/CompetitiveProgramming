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

// 強連結成分分解をします。scc[i]で頂点iが何番目の成分に含まれているかが分かる。
 // StronglyConnectedComponents(グラフ);のあと、build(重みなしグラフ);をする。
 template <typename G>
 struct StronglyConnectedComponents {
   const G &g;
   VV<ll> ng, rg;          // normal-graphとreversed-graph
   vector<int> compo, order, used;  // compo…頂点がどの成分に属しているか、order…帰りがけ順で何番目か
 
   StronglyConnectedComponents(G &g) : g(g), ng(g.size()), rg(g.size()), compo(g.size(), -1), used(g.size()) {
     for (int i = 0; i < g.size(); i++)
       for (auto t : g[i]) {
         ng[i].emplace_back((int)t);
         rg[(int)t].emplace_back(i);  // 逆辺
       }
   }
 
   // []で聞かれたときは成分番号を返す
   int operator[](int k) { return compo[k]; }
 
   void dfs(int now) {
     if (used[now]) return;
     used[now] = true;
     for (auto to : ng[now]) dfs(to);
     order.emplace_back(now);
   }
 
   void rdfs(int now, int count) {
     // used代わりに結果を入れていく
     if (compo[now] != -1) return;
     compo[now] = count;
     for (auto to : rg[now]) rdfs(to, count);
   }
 
   void build(VV<ll> &ret) {
     // 普通にDFS、辺の向きを変えてもう一度DFS
     for (int i = 0; i < ng.size(); i++) dfs(i);
     reverse(order.begin(), order.end());
     int group = 0;
     for (auto i : order)
       if (compo[i] == -1) rdfs(i, group), group++;
 
     // 縮めたグラフを構築する
     ret.resize(group);
     for (int i = 0; i < g.size(); i++) {  // 全ての辺について
       for (auto &to : g[i]) {
         int s = compo[i], t = compo[to];
         if (s != t) ret[s].emplace_back(t);
       }
     }
   }
 };

class Dag {
public:
  vector<vector<long long>> g;
  vector<long long> inCnt;
  vector<long long> sorted;
  bool sortedF=false;
  Dag(long long N) : g(N),inCnt(N){
  }
  void input(long long x,long long y){
    g[x].push_back(y);
    inCnt[y]++;
  }
  bool tpSort(){
    vector<long long> tmp=inCnt;
    deque<long long> dq;
    vector<long long> ans;
    for(int i=0;i<(int)g.size();i++)if(tmp[i]==0)dq.push_back(i);
    while(dq.size()!=0){
      long long v=dq.front();
      dq.pop_front();
      ans.push_back(v);
      for(auto &it:g[v]){
          tmp[it]--;
          if(tmp[it]==0)dq.push_back(it);
      }
    }
    sorted.swap(ans);
    sortedF=true;
    return sorted.size()==g.size();
  }
  long long longest(){
    if(sortedF==false)tpSort();
    vector<long long> dp(g.size(),0);
    long long res=0;
    for(auto &it1:sorted){
      for(auto &it2:g[it1]){
          dp[it2]=dp[it2]>dp[it1]+1 ? dp[it2] : dp[it1]+1;
      }
      res=res>dp[it1] ? res : dp[it1];
    }
    return res;
  }
};

class UnionFind {
public:
  vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<long long> siz; // siz[i]:iのサイズ　　(例) siz[3] = 2 : 3のサイズが2
  UnionFind(long long N) : par(N),siz(N,1LL) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) par[i] = i;
  }
  long long root(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  bool unite(long long x, long long y) { // xとyの木を併合
    x = root(x); //xの根をrx
    y = root(y); //yの根をry
    if (x == y) return false; //xとyの根が同じ(=同じ木にある)時はそのまま
    if (siz[x] < siz[y]) swap(x , y);
    siz[x] += siz[y];
    par[y] = x; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    return true;
  }
  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }
  long long size(long long x) { // 素集合のサイズ
    return siz[root(x)];
  }
};

int main(){
  init();
  inl(n,m);
  VV<ll> g(n);
  UnionFind uf(n);
  rep(i,m){
    inl(a,b);a--;b--;
    g[a].push_back(b);
    uf.unite(a,b);
  }
  
  StronglyConnectedComponents scc(g);
  VV<ll> ret;
  scc.build(ret);
  V<ll> cnt(ret.size());
  rep(i,n){
    cnt[scc[i]]++;
  }
  Dag d(ret.size());
  rep(i,ret.size()){
    rep(j,ret[i].size()){
      d.input(i,ret[i][j]);
    }
  }
  d.tpSort();
  //outv(d.sorted);
  ll ans=0;
  rep(i,ret.size())reps(j,i,ret.size()){
    if(uf.same(i,j)==false)continue;
    ans+=cnt[d.sorted[i]]*cnt[d.sorted[j]];
  }
  out(ans);
  return 0;
}