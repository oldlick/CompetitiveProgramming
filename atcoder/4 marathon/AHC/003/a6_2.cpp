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

ll loop;

class FractionC{
  public:
  ld x=0;
  ld y=0;
  ld estimated=-1;
  FractionC(){};
  ld z() const {//推定値
    if(estimated<=0)return 5000;
    return estimated;
  }
  ld w() const {//実測値
    if(y<=0)return -1;
    else return x/y;
  }
};

ld sigmoid(ld x){
  return (1/(1+exp(-x))-0.5)*2;
}

template<class T>
tuple<V<ld>,V<ll>> dijk(V<map<ll,T>> &g,ll s){
  ll n=g.size();
  priority_queue<pair<ld,ll>,vector<pair<ld,ll>>,greater<pair<ld,ll>>> q;
  q.push(mp(0,s));
  vector<ld> cost(n,INF);
  vector<ll> pre(n,-1);
  cost[s]=0;
  while(q.size()!=0){
    auto now=q.top();
    q.pop();
    if(cost[now.second]<now.first)continue;
    each(x,g[now.second]){
      if(cost[x.first]>cost[now.second]+x.second.z()){
        cost[x.first]=cost[now.second]+x.second.z();
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
  init();
  V<map<ll,FractionC>> g(900);
  rep(i,30)rep(j,29){
    g[i*30+j][i*30+j+1]=FractionC();
    g[i*30+j+1][i*30+j]=FractionC();
  }
  rep(i,29)rep(j,30){
    g[i*30+j][(i+1)*30+j]=FractionC();
    g[(i+1)*30+j][i*30+j]=FractionC();
  }
#ifndef ONLINE_JUDGE
  ld score=0;
  V<map<ll,ll>> gc(900);
  rep(i,30)rep(j,29){
    inl(tmp);
    gc[i*30+j][i*30+j+1]=tmp;
    gc[i*30+j+1][i*30+j]=tmp;
  }
  rep(i,29)rep(j,30){
    inl(tmp);
    gc[i*30+j][(i+1)*30+j]=tmp;
    gc[(i+1)*30+j][i*30+j]=tmp;
  }
#endif
  for(loop=0;loop<1000;loop++){
    ll s,t;
    bool reverseFlag=false;
    {
      inl(s1,s2,t1,t2);
      if(s2>t2){
        swap(s1,t1);
        swap(s2,t2);
        reverseFlag=true;
      }
      s=s1*30+s2;
      t=t1*30+t2;
    }
    {//推定値計算
      rep(mode,2){
        ll d=(mode==0?1:30);
        rep(i,30){
          V<pair<ld,ll>> left(29,{-1,-INF}),right(29,{-1,-INF});
          rep(j,29){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            if(g[x*30+y][x*30+y+d].w()!=-1)left[j]={g[x*30+y][x*30+y+d].w(),0};
            else if(j!=0)left[j]={left[j-1].fi,left[j-1].se+1};
          }
          for(ll j=28;j>=0;j--){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            if(g[x*30+y][x*30+y+d].w()!=-1)right[j]={g[x*30+y][x*30+y+d].w(),0};
            else if(j!=28)right[j]={right[j+1].fi,right[j+1].se+1};
          }
          rep(j,29){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            auto set=[&](ld value){
              //value-=5000;
              //value*=sigmoid(g[x*30+y][x*30+y+1].y-10)*0.2+1;
              //value+=5000;
              //value=min((ld)10000,max((ld)0,value));
              g[x*30+y][x*30+y+d].estimated=value;
              g[x*30+y+d][x*30+y].estimated=value;
            };
            if(left[j].se==0)set(left[j].fi);
            else if(left[j].se<0 && right[j].se<0)set(5000);
            else if(left[j].se<0)set(right[j].fi);
            else if(right[j].se<0)set(left[j].fi);
            else set((left[j].fi*right[j].se+right[j].fi*left[j].se)/(left[j].se+right[j].se));
          }
        }
      }
    }//推定値計算終わり
    auto [cost,pre]=dijk(g,s);
    V<ll> ans;
    ans.push_back(t);
    while(pre[ans.back()]!=-1){
      ans.push_back(pre[ans.back()]);
    }
    if(reverseFlag==false)reverse(all(ans));
    rep(i,ans.size()-1){
      ll x=ans[i+1]/30-ans[i]/30;
      ll y=ans[i+1]%30-ans[i]%30;
      if(x==1)cout<<'D';
      if(x==-1)cout<<'U';
      if(y==1)cout<<'R';
      if(y==-1)cout<<'L';
    }
    cout<<endl;
    ll b=0;
#ifndef ONLINE_JUDGE
    {
      inl(a);
      ind(e);
      rep(i,ans.size()-1){
        b+=gc[ans[i]][ans[i+1]];
      }
      score+=powl(0.998,1000-(loop+1))*a*2312311/b;
    }
#else
    in(b);
#endif
    {//実測値記録
      ld weight=b/ans.size();
      rep(i,ans.size()-1){
        /*weight=b-(cost[t]-g[ans[i]][ans[i+1]].z());
        weight/=ans.size();
        weight=(weight+g[ans[i]][ans[i+1]].w())/2;
        weight=min((ld)10000,max((ld)0,weight));*/
        ld alpha=(ld)30/ans.size();
        //alpha=1;
        g[ans[i]][ans[i+1]].x+=weight*alpha;
        g[ans[i]][ans[i+1]].y+=1*alpha;
        g[ans[i+1]][ans[i]].x+=weight*alpha;
        g[ans[i+1]][ans[i]].y+=1*alpha;
      }
    }//実測値記録終わり
  }
#ifndef ONLINE_JUDGE
  {
#ifndef RESULT_ONLY
    ld errorSum=0;
    ll errorCnt=0;
    auto output=[&](ll p1,ll p2){
        if(g[p1][p2].w()==-1)cerr<<"   -";
        else cerr<<setw(4)<<(int)g[p1][p2].w();
        cerr<<":"<<setw(4)<<(int)g[p1][p2].z()<<"[";
        if(g[p1][p2].y==0)cerr<<" -";
        else cerr<<setw(2)<<(int)g[p1][p2].y;
        cerr<<"]";
        errorSum+=(g[p1][p2].z()-gc[p1][p2])*(g[p1][p2].z()-gc[p1][p2]);
        errorCnt++;
    };
    rep(x,30){
      rep(y,30){
        if(x!=0)output(x*30+y,(x-1)*30+y);
        cerr<<"                           ";
      }
      cerr<<endl;
      rep(y,30){
        cerr<<" ";
        if(y!=0)output(x*30+y,x*30+y-1);
        cerr<<"     ("<<setw(2)<<x<<"/"<<setw(2)<<y<<") ";
        if(y!=29)output(x*30+y,x*30+y+1);
      }
      cerr<<endl;
      rep(y,30){
        if(x!=29)output(x*30+y,(x+1)*30+y);
        cerr<<"                           ";
      }
      cerr<<endl;
    }
    cerr<<pow(errorSum/errorCnt,0.5)<<endl;
#endif
    cerr<<(ll)round(score)<<endl;
  }
#endif
  return 0;
}