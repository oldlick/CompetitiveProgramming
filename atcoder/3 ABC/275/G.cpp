// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : G.cpp
// Version  : ver 1.0
// Date     : 2022-10-29 Sat 20:53:52
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

ld angle(pair<ld,ld> a,pair<ld,ld> b,pair<ld,ld> c){
    pair<ld,ld> v1={b.fi-a.fi,b.se-a.se};
    pair<ld,ld> v2={c.fi-b.fi,c.se-b.se};
    return v1.fi*v2.se-v1.se*v2.fi;
}

int main(){
    init();
    inl(n);
    V<pair<ld,ld>> p;
    rep(i,n){
        inl(a,b,c);
        if(a==0||b==0)continue;
        p.push_back({(ld)c/a,(ld)c/b});
    }
    debug(p);
    sort(all(p),[](pair<ld,ld> const&l,pair<ld,ld> const&r){
        return angle(l,{0,0},r)<0;
    });
    reverse(all(p));
    p.push_back({0,0});
    reverse(all(p));
    debug(p);
    
    V<ll> use;
    rep(i,p.size()){
        while(use.size()>=2){
            ll pre=use[use.size()-2];
            ll now=use[use.size()-1];
            ll nxt=i;
            //debug(pre,now,nxt);
            if(angle(p[pre],p[now],p[nxt])>0)break;
            use.pop_back();
        }
        use.push_back(i);
        //debug(use);
    }
    debug(use);

    ld ans=0;
    each(x,p){
        chmax(ans,min(x.fi,x.se));
    }
    debug(ans);
    reps(i,1,use.size()-1){
        auto item1=p[use[i]];
        auto item2=p[use[i+1]];
        debug(item1,item2);
        item1={1/item1.fi,1/item1.se};
        item2={1/item2.fi,1/item2.se};
        ld x1=(item2.se-item2.fi)/(item1.fi*item2.se-item2.fi*item1.se);
        ld x2=(item1.se-item1.fi)/(item2.fi*item1.se-item1.fi*item2.se);
        debug(x1,x2);
        chmax(ans,x1+x2);
    }
    print(ans);
    return 0;
}
/*
5
60 12 60
20 20 60
12 60 60
15 15 60
30 30 60

5
60 12 60
12 60 60
40 40 60
50 50 60
60 60 60

11
60 12 60
12 60 60
15 15 60
15 20 60
15 30 60
20 15 60
20 20 60
20 30 60
30 15 60
30 20 60
30 30 60

*/