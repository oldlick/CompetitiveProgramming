/*ver 6*/
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
template <typename T> void in1(T &s) {REP(i,s.size()){in(s[i]);}}
template <typename T> void in2(T &s,T &t) {REP(i,s.size()){in(s[i],t[i]);}}
template <typename T> void in3(T &s,T &t,T &u) {REP(i,s.size()){in(s[i],t[i],u[i]);}}
template <typename T> void in4(T &s,T &t,T &u,T &v) {REP(i,s.size()){in(s[i],t[i],u[i],v[i]);}}
template <typename T> void in5(T &s,T &t,T &u,T &v,T &w) {REP(i,s.size()){in(s[i],t[i],u[i],v[i],w[i]);}}
void out(){cout << endl;}
template <typename T,class... U> void out(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; out(u...);}
void die(){cout << endl;exit(0);}
template <typename T,class... U> void die(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; die(u...);}
template <typename T> void outv(T s) {REP(i,s.size()){if(i!=0)cout<<" ";cout<<s[i];}cout<<endl;}
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

bool hoge(list<ll>::iterator it,list<ll> &w){
	if(it==w.end())return false;
	REP(i,3){
		it=next(it);
		if(it==w.end())return false;
	}
	return true;
}

bool hoge2(list<ll>::iterator it,list<ll> &w){
	if(it==w.end())return false;
	it=next(it);
	if(it==w.end())return false;
	return true;
}

int main(){
	init();
	while(1){
		inl(n);
		if(n==0)exit(0);
		list<ll> w;
		REP(i,n){
			inl(tmp);
			w.push_back(tmp);
		}
		ll ans=0;
		bool f;
		do{
			f=false;
			for(auto it=w.begin();hoge(it,w);it=next(it)){
				auto it2=next(it);
				auto it3=next(it2);
				auto it4=next(it3);
				if(abs((*it2)-(*it3))==1){
					ll pre=(*it)-(*it2);
					ll aft=(*it3)-(*it4);
					if(pre*aft<0){
						//out(*it2,*it3);
						w.erase(it2,it4);
						f=true;
						ans+=2;
					}
				}else if(abs((*it2)-(*it3))==0){
					ll pre=(*it)-(*it2);
					ll aft=(*it3)-(*it4);
					if(pre*aft<=0){
						//out(*it2,*it3);
						w.erase(it2,it4);
						f=true;
						ans+=2;
					}
				}
			}
			if(f==false){
				for(auto it=w.begin();hoge2(it,w);it=next(it)){
					auto it2=next(it);
					if(abs((*it)-(*it2))<=1){
						//out(*it,*it2,"a");
						w.erase(it,next(it2));
						it=prev(it);
						f=true;
						ans+=2;
						break;
					}
				}
			}
		}while(f==true);
		out(ans);
	}
	return 0;
}