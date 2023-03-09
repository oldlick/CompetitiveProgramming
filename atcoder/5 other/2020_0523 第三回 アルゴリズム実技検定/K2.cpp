#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>
#include <list>
#include <map>
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
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
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
void in(){} template <typename T,class... U>
void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << endl;} template <typename T,class... U>
void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#define in1(A) REP(i,A.size()) in(A[i]);
#define in2(A,B) REP(i,A.size()) in(A[i],B[i]);
#define in3(s,t,u) REP(i,sz(s)){in(s[i] , t[i] , u[i]);}
#define in4(s,t,u,v) REP(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
#define all(v) (v).begin(),(v).end()
struct Point{ ld x,y; };
ld dist(Point a, Point b){return sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y));} // ２点間の距離 
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b;} 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )
#define EACH(x,v) for(auto& x : v)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define REFOR(i,a,b) for(ll i=(ll)b-1;i>=(ll)a;i++)
#define REP(i,n) for(ll i=0;i<(ll)n;i++)
#define REREP(i,n) for(ll i=(ll)n-1;i>=0;i--)
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

int main(){
	init();
    inl(n,q);
    vector<pair<ll,ll>> desk(n);
    vector<pair<ll,ll>> box(n);
    REP(i,n){
        desk[i]=pair<ll,ll>(i,i);
        box[i]=pair<ll,ll>(-1,-1);
    }
    REP(i,q){
        inl(f,t,x);f--;t--;x--;
        ll fend=desk[f].se;
        desk[f].se=box[x].fi;
        if(box[x].fi==-1){
            desk[f].fi=-1;
        }else{
            box[box[x].fi].se=-1;
        }
        if(desk[t].se==-1){
            desk[t].fi=x;
        }else{
            box[desk[t].se].se=x;
        }
        box[x].fi=desk[t].se;
        desk[t].se=fend;
        /*
        REP(j,n){
            cout<<"/"<<j<<":";
            ll cur=desk[j].fi;
            while(cur!=-1){
                cout<<cur;
                cur=box[cur].se;
            }
            cout<<endl;
        }*/
    }
    vector<ll> ans(n);
    REP(i,n){
        ll cur=desk[i].fi;
        while(cur!=-1){
            ans[cur]=i;
            cur=box[cur].se;
        }
    }
    REP(i,n){
        cout<<ans[i]+1<<endl;
    }
	return 0;
}