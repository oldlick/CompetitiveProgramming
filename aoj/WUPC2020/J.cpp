/*ver 5*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
#include <list>
#include <set>

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
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
#define EACH(x,v) for(auto& x : v)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define REFOR(i,a,b) for(ll i=(ll)b-1;i>=(ll)a;i--)
#define REP(i,n) for(ll i=0;i<(ll)n;i++)
#define REREP(i,n) for(ll i=(ll)n-1;i>=0;i--)
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
void out(){cout << endl;}
template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template <typename T> void die(T x){out(x); exit(0);}
template <typename T> void in1(T &s) {REP(i,s.size()){in(s[i]);}}
template <typename T> void in2(T &s,T &t) {REP(i,s.size()){in(s[i],t[i]);}}
template <typename T> void in3(T &s,T &t,T &u) {REP(i,s.size()){in(s[i],t[i],u[i]);}}
template <typename T> void in4(T &s,T &t,T &u,T &v) {REP(i,s.size()){in(s[i],t[i],u[i],v[i]);}}
template <typename T> void in5(T &s,T &t,T &u,T &v,T &w) {REP(i,s.size()){in(s[i],t[i],u[i],v[i],w[i]);}}
template <typename T> void outv(T s) {REP(i,s.size()){cout<<s[i]<<" ";}cout<<endl;}
template <typename T> void out1(T s) {REP(i,s.size()){out(s[i]);}}
template <typename T> void out2(T s,T t) {REP(i,s.size()){out(s[i],t[i]);}}
template <typename T> void out3(T s,T t,T u) {REP(i,s.size()){out(s[i],t[i],u[i]);}}
template <typename T> void out4(T s,T t,T u,T v) {REP(i,s.size()){out(s[i],t[i],u[i],v[i]);}}
template <typename T> void out5(T s,T t,T u,T v,T w) {REP(i,s.size()){out(s[i],t[i],u[i],v[i],w[i]);}}
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
template <typename T> T allSum(vector<T> a){T ans=T();EACH(it,a)ans+=it;return ans;}
ll ceilDiv(ll a,ll b) {return (a+b-1)/b;}
ld dist(pair<ld,ld> a, pair<ld,ld> b){return sqrt(abs(a.fi-b.fi)*abs(a.fi-b.fi)+abs(a.se-b.se)*abs(a.se-b.se));} // ２点間の距離 
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b;}
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )
const int mod = 1000000007;
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
	mint pow(ll t) const {
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
class UnionFind {
public:
	vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector<ll> siz; // siz[i]:iのサイズ　　(例) siz[3] = 2 : 3のサイズが2
	UnionFind(ll N) : par(N),siz(N,1LL) { //最初は全てが根であるとして初期化
	for(int i = 0; i < N; i++) par[i] = i;
	}
	ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	bool unite(ll x, ll y) { // xとyの木を併合
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
	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}
};
class Dag {
public:
	vvl g;
	vl inCnt;
	vl sorted;
	bool sortedF=false;
    Dag(ll N) : g(N),inCnt(N){
    }
	void input(ll x,ll y){
		g[x].pb(y);
		inCnt[y]++;
	}
	bool tpSort(){
		vl tmp=inCnt;
		deque<ll> dq;
		vl ans;
		REP(i,g.size())if(tmp[i]==0)dq.pb(i);
		while(dq.size()!=0){
			ll v=dq.front();
			dq.pop_front();
			ans.pb(v);
			EACH(it,g[v]){
				tmp[it]--;
				if(tmp[it]==0)dq.pb(it);
			}
		}
		sorted.swap(ans);
		sortedF=true;
		return sorted.size()==g.size();
	}
	ll longest(){
		if(sortedF==false)tpSort();
		vl dp(g.size(),0);
		ll res=0;
		EACH(it1,sorted){
			EACH(it2,g[it1]){
				chmax(dp[it2],dp[it1]+1);
			}
			chmax(res,dp[it1]);
		}
		return res;
	}
};

void re(UnionFind &uf,vvl &g_,ll a,ll l){
	static vl isuse(l,0);
	if(isuse[a]==1)return;
	uf.unite(a,l);
	isuse[a]=1;
	EACH(x,g_[a]){
		re(uf,g_,x,l);
	}
}

int main(){
	init();
	inl(n,m);
	vl a(m),b(m);
	in2(a,b);
	REP(i,m){
		a[i]--;
		b[i]--;
	}
	inl(q);
	vl x(q),y(q);
	in2(x,y);
	scc_graph graph(n);
	REP(i,m)graph.add_edge(a[i],b[i]);
	vector<vector<int>> s=graph.scc();

	vl t(n);
	REP(i,s.size()){
		REP(j,s[i].size()){
			t[s[i][j]]=i;
		}
	}

	set<pair<ll,ll>> tmp;
	vvl g(s.size());
	vvl g_(s.size());
	REP(i,m){
		ll a_=t[a[i]],b_=t[b[i]];
		if(a_==b_)continue;
		if(tmp.count(mp(a_,b_))==0){
			g[a_].pb(b_);
			g_[b_].pb(a_);
			tmp.insert(mp(a_,b_));
		}
	}
	ll l=s.size();

	UnionFind uf(l+1);
	re(uf,g_,t[0],l);
	REP(i,q){
		ll y_=t[y[i]-1];
		if(x[i]==1){
			re(uf,g_,y_,l);
		}else{
			out(YES(uf.same(y_,l)));
		}
	}
	return 0;
}