// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : E.cpp
// Version  : ver 1.0
// Date     : 2022-01-15 Sat 20:57:19
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

struct LowestCommonAncestorTreeMax {
        const int LOGM = 30;
        vector<int> depth, par_w;
        vector<vector<int>> parent, parmax;
        LowestCommonAncestorTreeMax(int root, const vector<vector<pair<int, int>>> &g) {
                int n = g.size();
                depth.resize(n);
                par_w.resize(n);
                parent.resize(LOGM);
                parmax.resize(LOGM);
                for (int i = 0; i < LOGM; i ++) { 
                        parent[i].resize(n);
                        parmax[i].resize(n);
                }
                function<void (int, int, int)> dfs = [&](int u, int prev, int d) {
                        parent[0][u] = prev;
                        parmax[0][u] = par_w[u];
                        depth[u] = d;
                        for (auto e : g[u]) { 
                                int v = e.first;
                                if (v != prev) { 
                                        par_w[v] = e.second;
                                        dfs(v, u, d + 1);
                                }
                        }
                };
                dfs(root, -1, 0);
                for (int k = 0; k < LOGM - 1; k ++) {
                        for (int i = 0; i < n; i ++) {
                                if (parent[k][i] < 0) { 
                                        parent[k + 1][i] = -1;
                                } else { 
                                        parent[k + 1][i] = parent[k][parent[k][i]];
                                        if (parent[k + 1][i] >= 0) {
                                                parmax[k + 1][i] = max(parmax[k][i], parmax[k][parent[k][i]]);
                                        }
                                }
                        }
                }
        }
        int lca(int u, int v) { 
                if (depth[u] > depth[v]) swap(u, v);
                for (int k = 0; k < LOGM; k ++) {
                        if ((depth[v] - depth[u]) >> k & 1) { 
                                v = parent[k][v];
                        }
                }
                if (u == v) return u;
                for (int k = LOGM - 1; k >= 0; k --) {
                        if (parent[k][u] != parent[k][v]) {
                                u = parent[k][u];
                                v = parent[k][v];
                        }
                }
                return parent[0][u];
        }
        int dist(int u, int v) {
                return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        }
        int getmax(int v, int ancestor) {
                int res = 0;
                int d = depth[v] - depth[ancestor];
                for (int k = 0; k < LOGM; k ++) {
                        if ((d >> k) & 1) {
                                res = max(res, parmax[k][v]);
                                v = parent[k][v];
                        }
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

vector<vector<pair<int, int>>> hoge(vector<vector<pair<int, int>>> g){
  ll n=g.size();
  UnionFind uf(n);
  priority_queue<V<ll>> q;
  rep(i,n){
    each(x,g[i]){
      if(i>=x.fi)continue;
      q.push({-x.se,i,x.fi});
    }
  }
  //out(q.size());
  vector<vector<pair<int, int>>> ans(n);
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(uf.same(now[1],now[2]))continue;
    uf.unite(now[1],now[2]);
    ans[now[1]].push_back({now[2],-now[0]});
    ans[now[2]].push_back({now[1],-now[0]});
  }
  return ans;
}

int main(){
  init();
  inl(n,m,q);
  vector<vector<pair<int, int>>> gAll(n);
  rep(i,m){
    inl(a,b,c);a--;b--;
    gAll[a].push_back(make_pair(b,c));
    gAll[b].push_back(make_pair(a,c));
  }
  vector<vector<pair<int, int>>> g=hoge(gAll);

  ll root = 0;
  LowestCommonAncestorTreeMax tree(root, g);
  rep(i,q){
    inl(s,t,w);s--;t--;
    int lca = tree.lca(s, t);
    int res = max(tree.getmax(s, lca), tree.getmax(t, lca));
    if(res<w)out("No");
    else out("Yes");
  }
  return 0;
}