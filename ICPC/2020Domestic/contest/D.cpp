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

V<ll> change(string &s,V<ll> &t){
	deque<char> q;
	V<ll> ret;
	rep(i,s.size()){
		if('A'<=s[i] && s[i]<='Z'){
			ret.push_back(t[s[i]-'A']);
		}else if(s[i]==')'){
			if(q.back()=='>')ret.push_back(-1);
			else ret.push_back(-2);
			q.pop_back();
			q.pop_back();
		}else{
			q.push_back(s[i]);
		}
	}
	return ret;
}

V<pair<ll,ll>> makelist(V<ll> s,ll n,ll c,ll b,ll m){
	deque<pair<ll,ll>> q;
	q.push_back(c,c);
	ll cnt=0;
	rep(i,s){
		if(s[i]==-1){
			cnt++;
		}
		if(s[i]==-2){
			cnt++;
		}
	}
	rep(i,m){
		if((b>>i)&1){

		}
	}

}

ll calc(V<ll> s,ll n,ll c,ll sEnd,ll m){
	ll ret=0;
	rep(i,sEnd){
		V<pair<ll,ll>> tmp=makelist(s,n,c,i,m);
		rep(j,tmp.size()){

		}
	}
}

bool solve(){
	inl(n);
	if(n==0)return false;
	ins(a);
	V<ll> table(26);
	rep(i,a.size()){
		table[a[i]-'A']=i;
	}
	ins(s);
	ins(t);
	V<ll> ds;
	V<ll> dt;
	ds=change(s,table);
	dt=change(t,table);
	rep(i,ds.size()/2)swap(ds[i],ds[ds.size()-i-1]);
	rep(i,dt.size()/2)swap(dt[i],dt[dt.size()-i-1]);
	outv(ds);
	outv(dt);

	ll sm=0,tm=0;
	rep(i,ds.size()){
		if(ds[i]<0)continue;
		sm++;
	}
	rep(i,dt.size()){
		if(dt[i]<0)continue;
		tm++;
	}
	ll sEnd=1,tEnd=1;
	rep(i,sm)sEnd*=2;
	rep(i,tm)tEnd*=2;
	ll ans=0;
	rep(j,n){
		ll tmp=1;
		tmp*=calc(ds,n,j,sEnd,sm);
		tmp*=calc(dt,n,j,tEnd,tm);
		ans+=tmp;
	}
	out(ans);
	return true;
}

int main(){
	init();
	while(solve());
	return 0;
}