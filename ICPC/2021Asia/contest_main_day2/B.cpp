// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : B.cpp
// Version  : ver 1.0
// Date     : 2022-03-16 Wed 09:06:50
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
//使用
void debug_f(){cerr<<endl;}
template<typename T,class... U>void debug_f(const T &t,const U &...u){debug_sub(t);if(sizeof...(u))cerr<<" ";debug_f(u...);}
#define debug(...) {cerr<<"["<<__LINE__<<":]\t"<<#__VA_ARGS__<<"\t";debug_f(__VA_ARGS__);}
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

string toDig(int n,int dig){
    string ret=to_string(n);
    reverse(ret.begin(),ret.end());
    for(int i=0;i<dig-(int)ret.size();i++) ret.push_back('0');
    reverse(ret.begin(),ret.end());
    return ret;
}

ll acc(map<string> m,string key){
  if(m.count(key)==1)return m[key];
  else return 0;
}

int main(){
  init();
  inl(n);
  V<string> a(n);
  input(a);
  if(n==1)die(300000);
  ll ans=0;
  map<string,ll> cnt2,cnt4;
  rep(i,n)cnt2[a[i].substr(4,2)]++;
  rep(i,n)cnt4[a[i].substr(2,4)]++;
  V<string> num3;
  ll max3=0;
  rep(k1,100)reps(k2,k1+1,100)reps(k3,k2+1,100){
    string k1_=toDig(k1_,2);
    string k2_=toDig(k2_,2);
    string k3_=toDig(k3_,2);
    ll tmp=acc(cnt2,k1_)+acc(cnt2,k2_)+acc(cnt2,k3_);
    if(tmp>max3){
      num3={k1_,k2_,k3_};
    }
  }
  V<string> num2;
  ll max2=0;
  rep(j,10000){
    string j_=toDig(j,4);
    ll tmp=acc(cnt4,j_);
    if(tmp>max2){
      num2={j_};
    }
  }
  if(num2[0].substr(2,2)==num3[0]){swap(num3[0],num3[2]);num3.pop_back();}
  if(num2[0].substr(2,2)==num3[1]){swap(num3[1],num3[2]);num3.pop_back();}
  if(num2[0].substr(2,2)==num3[2]){swap(num3[2],num3[2]);num3.pop_back();}
  if(num3.size()!=3){
    ll max3_=0;
    V<string> num3_;
    rep(k,100){
      string k_=toDig(k_,2);
      if(num3[0]==k_)continue;
      if(num3[1]==k_)continue;
      if(num2[0].substr(2,2)==k_)continue;
      ll tmp=acc(cnt2,k_);
      if(tmp>max3_){
        num3_={k_};
      }
    }
    num3.push_back(num3_[0]);
  }
  if(acc(cnt2,num3[0])+acc(cnt2,num3[1])+acc(cnt2,num3[2])+acc(cnt4,num2[0])>=n){
    ll minV=INF;
    ll minI=0;
    if(acc(cnt2,num3[0])<minV)minI=0;
    if(acc(cnt2,num3[1])<minV)minI=1;
    if(acc(cnt2,num3[2])<minV)minI=2;
    swap(num3[minI],num3[2]);
    num3.pop_back();
    num3.push_back("xx");
  }
  ll ans=0;
  ans+=300000;
  ans+=cnt2[num3[0]]*500;
  ans+=cnt2[num3[1]]*500;
  ans+=cnt2[num3[2]]*500;
  ans+=cnt4[num2[0]]*4000;
  print(ans);
  return 0;
}
/*
7
034207
924837
372745
382947
274637
083907
294837
*/