// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------
// FileName : A.cpp
// Version  : ver 1.0
// Date     : 2021-11-14 Sun 16:02:39
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
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) ((a)<=(x)&&(x)<=(b))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define debug cerr << "line : " << __LINE__ << " debug" << endl;
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) long double __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
void in(){}
template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
template <typename T> void in1(T &s) {rep(i,s.size()){in(s[i]);}}
template <typename T> void in2(T &s,T &t) {rep(i,s.size()){in(s[i],t[i]);}}
void out(){cout << endl;}
template <typename T,class... U> void out(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; out(u...);}
void err(){cerr << endl;}
template <typename T,class... U> void err(const T &t,const U &...u){cerr << t; if(sizeof...(u)) cerr << " "; err(u...);}
void die(){cout << endl;exit(0);}
template <typename T,class... U> void die(const T &t,const U &...u){cout << t; if(sizeof...(u)) cout << " "; die(u...);}
template <typename T> void outv(T s) {rep(i,s.size()){if(i!=0)cout<<" ";cout<<s[i];}cout<<endl;}
template <typename T> void out1(T s) {rep(i,s.size()){out(s[i]);}}
template <typename T> void out2(T s,T t) {rep(i,s.size()){out(s[i],t[i]);}}
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


std::random_device rnd;
std::mt19937 mt(rnd());

using point = pair<ll,ll>;
ll n=1000,m=50;
V<point> p;
std::chrono::time_point<std::chrono::_V2::system_clock> start;

ll dist(point a, point b){return abs(a.fi-b.fi)+abs(a.se-b.se);} // ２点間の距離 
ll dist(ll a, ll b){
  return abs(p[a].fi-p[b].fi)+abs(p[a].se-p[b].se);
}
ll dist(V<ll> path){
  ll ret=0;
  rep(i,path.size()-1)ret+=dist(path[i],path[i+1]);
  return ret;
}
ll diffSwapPointDist(V<ll> path,ll idx1,ll idx2){
  ll ret=0;
  ret-=dist(path[idx1-1],path[idx1]);
  ret-=dist(path[idx1],path[idx1+1]);
  ret-=dist(path[idx2-1],path[idx2]);
  ret-=dist(path[idx2],path[idx2+1]);
  ret+=dist(path[idx1-1],path[idx2]);
  ret+=dist(path[idx2],path[idx1+1]);
  ret+=dist(path[idx2-1],path[idx1]);
  ret+=dist(path[idx1],path[idx2+1]);
  return ret;
}
ll diffSwapEdgeDist(V<ll> path,ll idx1,ll idx2){
  ll ret=0;
  ll p1_1=path[idx1];
  ll p1_2=path[idx1+1];
  ll p2_1=path[idx2];
  ll p2_2=path[idx2+1];
  ret-=dist(p1_1,p1_2);
  ret-=dist(p2_1,p2_2);
  ret+=dist(p1_1,p2_1);
  ret+=dist(p1_2,p2_2);
  return ret;
}
ll diffAddDist(V<ll> path,ll pre_idx,ll add){
  ll ret=0;
  ret-=dist(path[pre_idx],path[pre_idx+1]);
  ret+=dist(path[pre_idx],add);
  ret+=dist(add,path[pre_idx+1]);
  return ret;
}
ll diffAddDist(ll pre,ll add,ll nxt){
  ll ret=0;
  ret-=dist(pre,nxt);
  ret+=dist(pre,add);
  ret+=dist(add,nxt);
  return ret;
}


void showAns(V<ll> &r,V<ll> &ans){
  cout<<r.size()<<" ";
  each(x,r)cout<<x+1<<" ";
  cout<<endl;
  cout<<ans.size()<<" ";
  each(x,ans)cout<<p[x].fi<<" "<<p[x].se<<" ";
  cout<<endl;
}

V<ll> makeR(){
  VV<ll> st;
  rep(i,n)st.push_back({max(dist(p[i],p[n*2]),dist(p[i+n],p[n*2])),i});
  sort(all(st));
  V<ll> r;
  rep(i,m)r.push_back(st[i][1]);
  return r;
}

V<ll> makeRandomR(){
  VV<ll> st;
  rep(i,n)st.push_back({max(dist(p[i],p[n*2]),dist(p[i+n],p[n*2])),i});
  sort(all(st));
  V<ll> r;
  std::uniform_int_distribution<> range1(1,100);
  std::uniform_int_distribution<> range2(0,99);
  while(1){
    ll line=range1(mt);
    r.clear();
    rep(i,n){
      if(range2(mt)<line)r.push_back(st[i][1]);
      if((int)r.size()==m)break;
    }
    if((int)r.size()==m)break;
  }
  return r;
}
V<ll> makeFlatRandomR(){
  VV<ll> st;
  rep(i,n)st.push_back({max(dist(p[i],p[n*2]),dist(p[i+n],p[n*2])),i});
  sort(all(st));
  V<ll> r;
  std::uniform_int_distribution<> range(0,n-1);
  set<ll> used;
  while(1){
    ll tmp=range(mt);
    if(used.count(tmp)==1)continue;
    r.push_back(st[tmp][1]);
    if((int)r.size()==m)break;
  }
  return r;
}

void twoOpt(V<ll> &ansV){
  rep(loop,100){
    bool f=false;
    rep(idx1,ansV.size()-1)reps(idx2,idx1+2,ansV.size()-1){
      if(diffSwapEdgeDist(ansV,idx1,idx2)<0){
        reverse(ansV.begin()+idx1+1,ansV.begin()+idx2+1);
        f=true;
      }
    }
    if(f==false)break;
  }
  std::uniform_int_distribution<> range1(1,ansV.size()-2);
  rep(loop,100){
    ll idx1=range1(mt),idx2=range1(mt);
    if(diffSwapPointDist(ansV,idx1,idx2)<0){
      swap(ansV[idx1],ansV[idx2]);
    }
    //showAns(r,ansV);
  }
}

void twoOptAfterAdded(V<ll> &ansV){
  rep(loop,100){
    bool f=false;
    rep(idx1,ansV.size()-1)reps(idx2,idx1+2,ansV.size()-1){
      if(diffSwapEdgeDist(ansV,idx1,idx2)<0){
        bool exist=false;
        set<ll> s;
        reps(i,idx1+1,idx2+1){
          ll tmp=ansV[i];
          if(tmp!=n*2)tmp%=n;
          if(s.count(tmp)==1){
            exist=true;
            break;
          }
          s.insert(tmp);
        }
        if(exist==false){
          reverse(ansV.begin()+idx1+1,ansV.begin()+idx2+1);
          f=true;
        }
      }
    }
    if(f==false)break;
  }
  std::uniform_int_distribution<> range1(1,ansV.size()-2);
  rep(loop,100){
    ll idx1=range1(mt),idx2=range1(mt);
    if(idx1>idx2)swap(idx1,idx2);
    if(diffSwapPointDist(ansV,idx1,idx2)<0){
      bool exist=false;
      reps(i,idx1+1,idx2){
        ll tmp=ansV[i];
        if(tmp!=n*2)tmp%=n;
        if(ansV[idx1]%n==tmp||ansV[idx2]%n==tmp){
          exist=true;
          break;
        }
      }
      if(exist==false){
        //swap(ansV[idx1],ansV[idx2]);
      }
    }
    //showAns(r,ansV);
  }
}

void insertToPoint(V<ll> &ansV){
  list<ll> ansL;
  rep(i,ansV.size())ansL.push_back(ansV[i]);
  for(auto it1=ansL.cbegin();it1!=ansL.cend();it1=next(it1)){
    ll x=*it1;//挿入届元idx
    if(x>=n)continue;
    auto ins=it1;
    ll mn=INF;
    for(auto it2=it1;next(it2)!=ansL.cend();it2=next(it2)){
      ll tmp=diffAddDist(*it2,x+n,*next(it2));
      if(mn>tmp){
        mn=tmp;
        ins=it2;
      }
    }
    ansL.insert(next(ins),x+n);
  }
  rep(loop,10){
    for(auto it1=ansL.cbegin();it1!=ansL.cend();it1=next(it1)){
      ll x=*it1;//挿入届先idx
      if(x<n||x==n*2)continue;
      ll base=diffAddDist(*prev(it1),*it1,*next(it1));
      auto ins=ansL.cbegin();
      ll mn=INF;
      bool f=false;
      for(auto it2=ansL.cbegin();next(it2)!=ansL.cend();it2=next(it2)){
        if(*it2==x-n)f=true;
        if(f==false)continue;
        if(*it2==x)continue;
        if(*next(it2)==x)continue;
        ll tmp=diffAddDist(*it2,x,*next(it2));
        if(mn>tmp){
          mn=tmp;
          ins=it2;
        }
      }
      if(mn<base){
        it1=prev(it1);
        ansL.erase(next(it1));
        ansL.insert(next(ins),x);
      }
    }
  }
  ansV.resize(0);
  for(auto it1=ansL.cbegin();it1!=ansL.cend();it1=next(it1)){
    ansV.push_back(*it1);
  }
}

V<ll> r2Ans(V<ll> &r){
  V<ll> ansV;
  ansV.push_back(n*2);
  rep(i,r.size())ansV.push_back(r[i]);
  ansV.push_back(n*2);
  twoOpt(ansV);
  insertToPoint(ansV);
  twoOptAfterAdded(ansV);
  return ansV;
}

int main(){
  start = chrono::system_clock::now();
  init();
  p.resize(n*2+1);
  rep(i,n){
    inl(a,b,c,d);
    p[i]={a,b};
    p[n+i]={c,d};
  }
  p[n*2]={400,400};
  auto mn_r=makeR();
  auto mn_ans=r2Ans(mn_r);
  ll mn_val=dist(mn_ans);
  showAns(mn_r,mn_ans);
  while(1){
    auto end = chrono::system_clock::now();
    auto msec = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    if(msec>1000)break;
    V<ll> r;
    if(msec<900)r=makeRandomR();
    else r=makeFlatRandomR();
    auto ans=r2Ans(r);
    ll val=dist(ans);
    if(val<mn_val){
      mn_r=r;
      mn_ans=ans;
      mn_val=val;
      //showAns(mn_r,mn_ans);
    }
  }
  while(1){
    auto end = chrono::system_clock::now();
    auto msec = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    if(msec>1950)break;
    twoOptAfterAdded(mn_ans);
  }
  showAns(mn_r,mn_ans);
  ll d=dist(mn_ans);
  err(d,round(1e8/(1000+d)));
  return 0;
}