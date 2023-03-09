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

bool isOk(V<ll> x,V<ll> y,ld key){
	ll n=x.size();
	UnionFind uf(n+2);
	rep(i,n)reps(j,i+1,n){
		ld d=dist(make_pair(x[i],y[i]),make_pair(x[j],y[j]));
		if(d<=key*2)uf.unite(i,j);
	}
	rep(i,n){
		if(abs(100-y[i])<=key*2)uf.unite(i,n);
		if(abs(y[i]+100)<=key*2)uf.unite(i,n+1);
	}
	if(uf.same(n,n+1))return false; //d is ok
	else return true;
}
int main(){
	init();
	inl(n);
	V<ll> x(n),y(n);
	in2(x,y);

	ld ok=0;
	ld ng=100;
	while(abs(ok-ng)>1e-9){
		ld mid=(ok+ng)/2;
		if(isOk(x,y,mid))ok=mid;
		else ng=mid;
	}
	out(ok);
	return 0;
}