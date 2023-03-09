//ver 8.1
#include <bits/stdc++.h>
using namespace std;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);cerr << fixed << setprecision(15);}
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

ll n,m;
V<string> s;

struct line{
  ll x;
  ll y;
  ll idx;
  ll dir;
};

struct draft{
  V<string> board;
  V<line> lines;
  ll score;
};


void calc(draft &ans){
  ans.lines.clear();
  ans.score=0;
  rep(k,m){
    rep(dir,2)rep(i,n)rep(j,n){
      bool f=true;
      rep(l,s[k].size()){
        if(s[k][l]!=ans.board[(i+l*dir)%n][(j+l*(1-dir))%n]){
          f=false;
          break;
        }
      }
      if(f==true){
        ans.lines.push_back({i,j,k,dir});
      }
    }
  }
  V<ll> use(m);
  each(x,ans.lines){
    if(use[x.idx]==0){
      use[x.idx]=1;
      ans.score++;
    }
  }
}

void fastCalc(draft &ans,ll x,ll y,ll length,ll dir){
  ll xBegin[2],xEnd[2];
  ll yBegin[2],yEnd[2];
  if(dir==0){
    xBegin[0]=x;
    xEnd[0]=x;
    yBegin[0]=y-12+1;
    yEnd[0]=y+length-1;
    xBegin[1]=x-12+1;
    xEnd[1]=x;
    yBegin[1]=y;
    yEnd[1]=y+length-1;
    /*
    yBegin[0]=(yBegin[0]+n)%n;
    yEnd[0]=(yEnd[0]+n)%n;
    xBegin[1]=(xBegin[1]+n)%n;
    yEnd[1]=(yEnd[1]+n)%n;
    */
  }else{
    xBegin[0]=x;
    xEnd[0]=x+length-1;
    yBegin[0]=y-12+1;
    yEnd[0]=y;
    xBegin[1]=x-12+1;
    xEnd[1]=x+length-1;
    yBegin[1]=y;
    yEnd[1]=y;
    /*
    xEnd[0]=(xEnd[0]+n)%n;
    yBegin[0]=(yBegin[0]+n)%n;
    xBegin[1]=(xBegin[1]+n)%n;
    xEnd[1]=(xEnd[1]+n)%n;
    */
  }
  rep(d,2){
    if(xEnd[d]-xBegin[d]>=n)xEnd[d]=xBegin[d]+n-1;
    xBegin[d]=(xBegin[d]+n)%n;
    xEnd[d]=(xEnd[d]+n)%n;
    if(yEnd[d]-yBegin[d]>=n)yEnd[d]=yBegin[d]+n-1;
    yBegin[d]=(yBegin[d]+n)%n;
    yEnd[d]=(yEnd[d]+n)%n;
    //out("##",xBegin[d],xEnd[d],yBegin[d],yEnd[d]);
  }
  //out("a");
  V<line> lines;
  each(it,ans.lines){
    bool f=true;
    //if(it.idx==210)out("------");
    //out(it.idx,it.x,it.y,it.dir);
    //out(xEnd[it.dir]+1,xBegin[it.dir]-1);
    //out(IN(xBegin[it.dir],xEnd[it.dir],it.x),!IN(xEnd[it.dir]+1,xBegin[it.dir]-1,it.x));
    if((xBegin[it.dir]<=xEnd[it.dir])&&IN(xBegin[it.dir],xEnd[it.dir],it.x)\
    ||(xBegin[it.dir]>xEnd[it.dir])&&!IN(xEnd[it.dir]+1,xBegin[it.dir]-1,it.x)){
      //out(yEnd[it.dir]+1,yBegin[it.dir]-1);
      //out(IN(yBegin[it.dir],yEnd[it.dir],it.y),!IN(yEnd[it.dir]+1,yBegin[it.dir]-1,it.y));  
      if((yBegin[it.dir]<=yEnd[it.dir])&&IN(yBegin[it.dir],yEnd[it.dir],it.y)\
      ||(yBegin[it.dir]>yEnd[it.dir])&&!IN(yEnd[it.dir]+1,yBegin[it.dir]-1,it.y)){
        f=false;
      }
    }
    if(f)lines.push_back(it);
    //else out("sub:idx=",it.idx);
  }
  //out("lines.size()",ans.lines.size(),lines.size());
  ans.lines=lines;

  rep(d,2){
    if(xBegin[d]>xEnd[d])xEnd[d]+=n;
    if(yBegin[d]>yEnd[d])yEnd[d]+=n;
    reps(i,xBegin[d],xEnd[d]+1)reps(j,yBegin[d],yEnd[d]+1)rep(k,m){
      bool f=true;
      rep(l,s[k].size()){
        if(s[k][l]!=ans.board[(i+l*d)%n][(j+l*(1-d))%n]){
          f=false;
          break;
        }
      }
      if(f==true){
        ans.lines.push_back({i%n,j%n,k,d});
        //out("add:idx=",k);
      }
    }
  }
  ans.score=0;
  V<ll> use(m);
  each(x,ans.lines){
    if(use[x.idx]==0){
      use[x.idx]=1;
      ans.score++;
    }
  }
}

//焼きなまし法 高速化 デバッグ ビームSearchの幅増やす
int main(){
  auto start = chrono::system_clock::now();
  std::mt19937 mt(0);
  init();
  in(n,m);
  s.resize(m);
  in1(s);
  ll parallel=2;
  V<draft> list(parallel);
  {
    auto &now=list[0].board;
    now.resize(n);
    ll cnt=0;
    rep(i,n){
      while(now[i].size()+s[cnt].size()<=n)now[i]+=s[cnt++];
      now[i]+=string(n-now[i].size(),'.');
    }
    calc(list[0]);
  }
  rep(i,parallel-1)list[i+1]=list[0];
  std::uniform_int_distribution<> randM(0, m-1);
  std::uniform_int_distribution<> randN(0, n-1);
  std::uniform_int_distribution<> rand2(0, 1);
  std::uniform_int_distribution<> rand100(0, 99);
  {
    ll cnt=0;
    while(1){
      auto end = chrono::system_clock::now();
      auto msec = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
      if(msec>2960)break;
      ll dir=rand2(mt);
      ll x=randN(mt);
      ll y=randN(mt);
      ll writeLine=randM(mt);
      //x=0,y=0,writeLine=1,dir=0;
      //x=0,y=0,writeLine=1,dir=1;
      auto now=list[cnt%parallel];
      rep(l,s[writeLine].size()){
        now.board[(x+l*dir)%n][(y+l*(1-dir))%n]=s[writeLine][l];
      }
      fastCalc(now,x,y,s[writeLine].size(),dir);
      //list[0]=now;
      //if(cnt==129)break;
      ll place=0;
      rep(i,parallel){
        if(list[i].score<list[place].score)place=i;
      }
      if(now.score>list[place].score){
        list[place]=now;
      }else if(rand100(mt)<20){
        list[place]=now;
      }
      cnt++;
      rep(i,parallel)cout<<(ll)round(list[i].score*1e8/m)<<" ";
      cout<<endl;
    }
    //cerr<<cnt<<endl;
  }
  ll cnt=0;
  //each(x,list[0].lines)out(cnt++,":",x.idx,x.dir);

  /*
  draft tmp=list[0];
  V<ll> aa;
  rep(i,tmp.lines.size()){
    aa.push_back(tmp.lines[i].idx);
  }
  sort(all(aa));
  calc(tmp);
  bool f=true;
  rep(i,tmp.lines.size()){
    if(tmp.lines[i].idx!=aa[i])f=false;
    out(tmp.lines[i].idx,aa[i]);
  }
  if(f==false)out("------ERROR------");
  */

  ll place=0;
  rep(i,parallel){
    if(list[i].score>list[place].score)place=i;
  }
  cerr<<(ll)round(list[place].score*1e8/m)<<endl;
  rep(i,n){
    out(list[0].board[i]);
  }
  return 0;
}