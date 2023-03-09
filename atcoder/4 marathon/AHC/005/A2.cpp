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

std::random_device rnd;
std::mt19937 mt(rnd());

ll n;
bool ch(ll a,ll b){
  return !(a<0||a>=n||b<0||b>=n);
}

template<class T>
tuple<V<T>,V<ll>> dijk(VV<pair<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<T,ll>,vector<pair<T,ll>>,greater<pair<T,ll>>> q;
  q.push(mp(0,s));
  vector<T> cost(n,INF);
  vector<ll> pre(n,-1);
  cost[s]=0;
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second){
        cost[x.first]=cost[now.second]+x.second;
        pre[x.first]=now.second;
        q.push(mp(cost[x.first],x.first));
      }
    }
    //outv(cost);
  }
  //outv(cost);
  return {cost,pre};
}

int main(){
  auto start = chrono::system_clock::now();
  init();
  in(n);
  ll s;
  {
    inl(tmp1,tmp2);
    s=tmp1*n+tmp2;
  }
  V<string> c(n);
  in1(c);
  VV<pair<ll,ll>> g(n*n);
  rep(i,n)rep(j,n){
    ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    rep(k,4){
      if(ch(i+dx[k],j+dy[k])&&c[i+dx[k]][j+dy[k]]!='#'){
        g[(i+dx[k])*n+j+dy[k]].push_back(make_pair(i*n+j,c[i+dx[k]][j+dy[k]]-'0'));
      }
    }
  }
  V<ll> p;
  {
    VV<ll> mark(n,V<ll>(n));
    rep(i,n)rep(j,n){
      if(c[i][j]=='#')continue;
      ll dx[2]={1,0},dy[2]={0,1};
      ll cnt=0;
      rep(k,2){
        if(ch(i+dx[k],j+dy[k])&&c[i+dx[k]][j+dy[k]]!='#')cnt++;
        else if(ch(i-dx[k],j-dy[k])&&c[i-dx[k]][j-dy[k]]!='#')cnt++;
      }
      if(cnt!=2)continue;
      bool f=false;
      rep(k,n){
        if(f||!ch(i+k,j)||c[i+k][j]=='#')break;
        if(mark[i+k][j]==0)f=true;
      }
      rep(k,n){
        if(f||!ch(i,j+k)||c[i][j+k]=='#')break;
        if(mark[i][j+k]==0)f=true;
      }
      rep(k,n){
        if(f||!ch(i-k,j)||c[i-k][j]=='#')break;
        if(mark[i-k][j]==0)f=true;
      }
      rep(k,n){
        if(f||!ch(i,j-k)||c[i][j-k]=='#')break;
        if(mark[i][j-k]==0)f=true;
      }
      if(f==false)continue;
      p.push_back(i*n+j);
      rep(k,n){
        if(!ch(i+k,j)||c[i+k][j]=='#')break;
        mark[i+k][j]=1;
      }
      rep(k,n){
        if(!ch(i,j+k)||c[i][j+k]=='#')break;
        mark[i][j+k]=1;
      }
      rep(k,n){
        if(!ch(i-k,j)||c[i-k][j]=='#')break;
        mark[i-k][j]=1;
      }
      rep(k,n){
        if(!ch(i,j-k)||c[i][j-k]=='#')break;
        mark[i][j-k]=1;
      }
    }
  }
  p.push_back(s);
  VV<ll> pLen(p.size(),V<ll>(p.size()));
  rep(i,p.size()){
    auto[cost,pre]=dijk(g,p[i]);
    rep(j,p.size())pLen[i][j]=cost[p[j]];
  }
  ll mnLen=INF;
  V<ll> mnRoot(p.size());
  rep(i,mnRoot.size())mnRoot[i]=i;
  V<ll> root=mnRoot;
  std::uniform_int_distribution<> range(0,mnRoot.size()-2);
  while(1){
    auto end = chrono::system_clock::now();
    auto msec = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    if(msec>2900)break;
    auto now=root.back();
    ll len=0;
    rep(i,root.size()){
      ll place=root[i];
      len+=pLen[now][place];
      now=root[i];
    }
    //----//
    if(len<mnLen){
      mnLen=len;
      mnRoot=root;
    }else{
      root=mnRoot;
    }
    swap(root[range(mt)],root[range(mt)]);
    swap(root[range(mt)],root[range(mt)]);
  }
  string ans;
  auto now=p[mnRoot.back()];
  rep(i,mnRoot.size()){
    auto[cost,pre]=dijk(g,now);
    ll place=p[mnRoot[i]];
    string road;
    while(pre[place]!=-1){
      ll dif=pre[place]-place;
      if(dif==1)road.push_back('L');
      if(dif==-1)road.push_back('R');
      if(dif==n)road.push_back('U');
      if(dif==-n)road.push_back('D');
      place=pre[place];
    }
    reverse(all(road));
    ans.append(road);
    now=p[mnRoot[i]];
  }
  out(ans);
  cerr<<mnLen<<endl;
  return 0;
}