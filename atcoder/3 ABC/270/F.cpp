// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : F.cpp
// Version  : ver 1.0
// Date     : 2022-09-24 Sat 20:55:02
// -------------------------------------------------------------------------------
//Ver.12
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
#define press(v) v.erase( unique(v.begin(), v.end()), v.end() ) //隣接被り削除
#define ini(...) int __VA_ARGS__; input(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define ind(...) long double __VA_ARGS__; input(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; input(__VA_ARGS__)
//ヘルパー
template<typename>struct is_vector : false_type {};
template<typename T, typename ALLOCATOR>struct is_vector<vector<T, ALLOCATOR>> : true_type {};
template <typename T>constexpr auto is_vector_v = is_vector<T>::value;
template<typename>struct is_map : false_type {};
template<typename T, typename ALLOCATOR>struct is_map<map<T, ALLOCATOR>> : true_type {};
template <typename T>constexpr auto is_map_v = is_map<T>::value;
template<typename>struct is_set : false_type {};
template<typename T, typename ALLOCATOR>struct is_set<set<T, ALLOCATOR>> : true_type {};
template <typename T>constexpr auto is_set_v = is_set<T>::value;
template<typename>struct is_pair : false_type {};
template<typename T, typename ALLOCATOR>struct is_pair<pair<T, ALLOCATOR>> : true_type {};
template <typename T>constexpr auto is_pair_v = is_pair<T>::value;
//プロトタイプ宣言
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>void input_sub(T &t);
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>void input_sub(T &t);
template<typename T,typename enable_if<(is_vector_v<T>||is_map_v<T>||is_set_v<T>),nullptr_t>::type = nullptr>void input_sub(T &t);
//定義
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>
void input_sub(T &t){cin>>t;}
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>
void input_sub(T &t){input_sub(t.first);input_sub(t.second);}
template<typename T,typename enable_if<(is_vector_v<T>||is_map_v<T>||is_set_v<T>),nullptr_t>::type = nullptr>
void input_sub(T &t){for(auto &x:t)input_sub(x);}
//使用
void input(){}
template<typename T,class... U>void input(T &t,U &...u){input_sub(t);input(u...);}
//プロトタイプ宣言
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>void print_sub(const T &t);
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>void print_sub(const T &t);
template<typename T,typename enable_if<(is_vector_v<T>||is_map_v<T>||is_set_v<T>),nullptr_t>::type = nullptr>void print_sub(const T &t);
//定義
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>
void print_sub(const T &t){cout<<t<<" ";}
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>
void print_sub(const T &t){print_sub(t.first);print_sub(t.second);}
template<typename T,typename enable_if<(is_vector_v<T>||is_map_v<T>||is_set_v<T>),nullptr_t>::type = nullptr>
void print_sub(const T &t){for(auto &x:t)print_sub(x);}
//使用
void print(){cout<<endl;}
template<typename T,class... U>void print(const T &t,const U &...u){print_sub(t);print(u...);}
void die(){cout<<endl;exit(0);}
template<typename T,class... U>void die(const T &t,const U &...u){print_sub(t);die(u...);}
//プロトタイプ宣言
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>void debug_sub(const T &t);
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>void debug_sub(const T &t);
template<typename T,typename enable_if<(is_vector_v<T>),nullptr_t>::type = nullptr>void debug_sub(const T &t);
template<typename T,typename enable_if<(is_set_v<T>),nullptr_t>::type = nullptr>void debug_sub(const T &t);
template<typename T,typename enable_if<(is_map_v<T>),nullptr_t>::type = nullptr>void debug_sub(const T &t);
template<> void debug_sub(const long long &t);
//定義
template<typename T,typename enable_if<!(is_vector_v<T>||is_map_v<T>||is_set_v<T>||is_pair_v<T>),nullptr_t>::type = nullptr>
void debug_sub(const T &t){cerr<<t;}
template<typename T,typename enable_if<(is_pair_v<T>),nullptr_t>::type = nullptr>
void debug_sub(const T &t){debug_sub(t.first);cerr<<":";debug_sub(t.second);}
template<typename T,typename enable_if<(is_vector_v<T>),nullptr_t>::type = nullptr>
void debug_sub(const T &t){cerr<<"[";for(int i=0;i<(int)t.size();i++){if(i!=0)cerr<<" ";debug_sub(t[i]);}cerr<<"]";}
template<typename T,typename enable_if<(is_set_v<T>),nullptr_t>::type = nullptr>
void debug_sub(const T &t){for(auto &x:t)debug_sub(x);}
template<typename T,typename enable_if<(is_map_v<T>),nullptr_t>::type = nullptr>
void debug_sub(const T &t){bool f=false;cerr<<"{";for(auto &x:t){if(f)cerr<<", ";f=true;debug_sub(x);}cerr<<"}";}
template<> void debug_sub(const long long &t){
    if(t<1000){cerr<<t; return;}
    string s=to_string(t);
    for(int i=0;i<(int)s.size();i++){
        if(i!=0 && (s.size()-i)%4==0)cerr<<"_";
        cerr<<s[i];
    }
}
//使用
#ifdef LOCAL_COMPILE
    void debug_f(){cerr<<endl;}
    template<typename T,class... U>void debug_f(const T &t,const U &...u){debug_sub(t);if(sizeof...(u))cerr<<" ";debug_f(u...);}
    #define debug(...) {cerr<<"["<<__LINE__<<":]\t"<<#__VA_ARGS__<<"\t";debug_f(__VA_ARGS__);}
#else
    void debug_f(){}
    template<typename T,class... U>void debug_f(const T &t,const U &...u){}
    #define debug(...){}
#endif
//その他
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

ll n;
ll solve(priority_queue<V<ll>> q){
    UnionFind uf(n+2);
    ll sum=0;
    while(q.size()){
        auto now = q.top();
        ll z=-now[0];
        ll a=now[1];
        ll b=now[2];
        q.pop();
        if(uf.same(a,b))continue;
        uf.unite(a,b);
        debug(a,b,z);
        sum+=z;
    }
    bool f=true;
    rep(i,n)if(uf.root(i)!=uf.root(0))f=false;
    if(f==false) return INF;
    debug(sum);
    return sum;
}

int main(){
    init();
    input(n);
    inl(m);
    V<ll> x(n),y(n);
    input(x,y);
    priority_queue<V<ll>> q;
    rep(i,m){
        inl(a,b,z);a--;b--;
        q.push({-z,a,b});
    }
    debug(x);
    debug(y);

    ll ans=INF;
    chmin(ans,solve(q));
    debug(ans);
    priority_queue<V<ll>> q1=q;
    rep(i,x.size())q1.push({-x[i],i,n});
    chmin(ans,solve(q1));
    debug(ans);
    rep(i,y.size())q1.push({-y[i],i,n+1});
    chmin(ans,solve(q1));
    debug(ans);
    priority_queue<V<ll>> q2=q;
    rep(i,y.size())q2.push({-y[i],i,n+1});
    chmin(ans,solve(q2));
    debug(ans);
    print(ans);
    return 0;
}