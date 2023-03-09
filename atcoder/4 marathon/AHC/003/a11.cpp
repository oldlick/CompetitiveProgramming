//ver 8.1
#include <bits/stdc++.h>
using namespace std;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);cerr << fixed << setprecision(15);}
using ll = long long;
using ld = double;
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


const ll EDGE_NUM=1800;
ll loop;

class FractionC{
  public:
  ld weight=5000;
  ld trust=0.1;
  ld estimated=5000;
  FractionC(){};
  ld z() const {//推定値
    if(estimated<=0){
      /*cerr<<"cost error["<<estimated<<"]"<<loop<<endl;
      exit(0);*/
      return 0.1;
    }
    return estimated;
  }
};

ld sigmoid(ld x,ld xmin=-1,ld xmax=1,ld ymin=0,ld ymax=1){
  x-=(xmax+xmin)/2;
  x/=(xmax-xmin)/2;
  ld ret=1/(1+exp(-x));
  ret*=(ymax-ymin);
  ret+=ymin;
  return ret;
}

ld variance(V<FractionC> a,ll s,ll t){
  ld sum=0,sum_2=0;
  ld cnt=0;
  reps(i,s,t){
    ld trust=a[i].trust;
    if(trust>20)trust=20;
    sum+=a[i].weight*trust;
    cnt+=trust;
  }
  if(cnt<0.0001)return 0;
  reps(i,s,t){
    ld trust=a[i].trust;
    if(trust>20)trust=20;
    sum_2+=powl(a[i].weight-sum/cnt,2)*trust;
  }
  return sum_2;
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

ll nodesToEdge(ll node1,ll node2){
  if(node1>node2)swap(node1,node2);
  ll base=node1*2;
  ll x=node2/30-node1/30;
  if(x==1)base++;
  return base;
}
tuple<ll,ll> EdgeToNodes(ll edge){
  ll node1=edge/2;
  ll node2=edge/2;
  if(edge%2==0)node2+=1;
  else node2+=30;
  return {node1,node2};
}

int main(int argc,char* argv[]){
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
  V<pair<bitset<EDGE_NUM>,ll>> edgesBitSet;
#ifndef ONLINE_JUDGE
  ld parameter;
  if(argc<=1){
    parameter=1;
  }else{
    ll tmp=stol(argv[1]);
    parameter=tmp/100.0;
  }
  ld score=0;
  V<ll> edgesBitSetCnt(1000);
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
      ld randomDValue=0;
      ld randomDTrust=0;
      ll randomDCnt=0;
      rep(mode,2){
        ll d=(mode==0?1:30);
        rep(i,30){
          V<ld> diff(28);
          V<FractionC> arr(29);
          rep(j,29){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            arr[j]=g[x*30+y][x*30+y+d];
          }
          rep(j,28)diff[j]=abs(variance(arr,0,j+1)+variance(arr,j+1,29));
          ll divPoint=0;
          rep(j,28)if(diff[j]<diff[divPoint])divPoint=j;
          ld leftAvg=0,rightAvg=0;
          ld leftCnt=0,rightCnt=0;
          rep(j,29){
            if(j<=divPoint){
              leftAvg+=arr[j].weight*arr[j].trust;
              leftCnt+=arr[j].trust;
            }else{
              rightAvg+=arr[j].weight*arr[j].trust;
              rightCnt+=arr[j].trust;
            }
          }
          if(leftCnt<0.0001)leftAvg=5000;
          else leftAvg/=leftCnt;
          if(rightCnt<0.0001)rightAvg=5000;
          else rightAvg/=rightCnt;
          /*if(loop==396&&mode==0&&i==22){
            out(divPoint,diff[divPoint]);
            outv(diff);
            rep(j,28)out(j,variance(arr,0,j+1),variance(arr,j+1,29));
            out(leftAvg,rightAvg);
          }*/
          /*if(diff[divPoint]>0.00){
            out("a",mode,i,divPoint,diff[divPoint]);
            outv(diff);
          }*/
          rep(j,29){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            auto nowPoint=g[x*30+y][x*30+y+d];
            auto set=[&](ld value){
              g[x*30+y][x*30+y+d].estimated=value;
              g[x*30+y+d][x*30+y].estimated=value;
            };
            if(nowPoint.trust==0 && j==divPoint+1){
              divPoint++;
            }else if(j<=divPoint){
              randomDValue+=abs(nowPoint.weight-leftAvg)*nowPoint.trust;
              randomDTrust+=nowPoint.trust;
              randomDCnt++;
              set(leftAvg);
            }else{
              randomDValue+=abs(nowPoint.weight-rightAvg)*nowPoint.trust;
              randomDTrust+=nowPoint.trust;
              randomDCnt++;
              set(rightAvg);
            }
          }
        }
      }
      randomDValue/=randomDTrust;
      randomDValue*=2;
      randomDTrust/=randomDCnt;
      //out(randomDValue,randomDTrust);
      rep(mode,2){
        ll d=(mode==0?1:30);
        rep(i,30){
          rep(j,29){
            ll x=i,y=j;
            if(mode==1)swap(x,y);
            auto nowPoint=g[x*30+y][x*30+y+d];
            auto set=[&](ld value){
              chmax(value,0.1);
              g[x*30+y][x*30+y+d].estimated=value;
              g[x*30+y+d][x*30+y].estimated=value;
            };
            ld rangeMin=520/(randomDTrust+1)+100;
            ld range=randomDValue;
            if(randomDValue<rangeMin)range=rangeMin;
            if(2000<randomDValue)range=2000;
            range=((range-100)*2000+(2000-range)*rangeMin)/1900;
            //ld range=randomDValue*sigmoid(randomDTrust,,,0.5,1.5);
            ld adjust=sigmoid(nowPoint.weight-nowPoint.estimated,-range,range,-range,range);
            set(nowPoint.estimated+adjust);
            //set((nowPoint.estimated+nowPoint.weight)/2);
          }
        }
      }
    }//推定値計算終わり
    //if(loop==926)break;
    auto [cost,pre]=dijk(g,s);
    V<ll> ansPlace;
    ansPlace.push_back(t);
    while(pre[ansPlace.back()]!=-1){
      ansPlace.push_back(pre[ansPlace.back()]);
    }
    if(reverseFlag==false)reverse(all(ansPlace));
    string ans;
    rep(i,ansPlace.size()-1){
      ll x=ansPlace[i+1]/30-ansPlace[i]/30;
      ll y=ansPlace[i+1]%30-ansPlace[i]%30;
      if(x==1)ans.push_back('D');
      if(x==-1)ans.push_back('U');
      if(y==1)ans.push_back('R');
      if(y==-1)ans.push_back('L');
    }
    out(ans);
    ll b=0;
#ifndef ONLINE_JUDGE
    {
      inl(a);
      ind(e);
      rep(i,ansPlace.size()-1){
        b+=gc[ansPlace[i]][ansPlace[i+1]];
      }
      score+=powl(0.998,1000-(loop+1))*a*2312311/b;
      b*=e;
    }
#else
    in(b);
#endif
    auto weightWrite=[&g](ld cost,bitset<EDGE_NUM> edgesBit,ld alpha=1){//実測値記録
      V<ll> edges;
      V<pair<ll,ll>> nodes(edges.size());
      ld difference=cost;
      rep(i,EDGE_NUM)if(edgesBit.test(i)){
        edges.push_back(i);
        nodes.push_back({get<0>(EdgeToNodes(i)),get<1>(EdgeToNodes(i))});
        difference-=g[nodes.back().fi][nodes.back().se].weight;
      }
      ld trustInvSum=0;
      rep(i,edges.size()){
        //trustSum+=g[nodes[i].fi][nodes[i].se].trust;
        trustInvSum+=1/(g[nodes[i].fi][nodes[i].se].trust+1);
      }
      V<ll> hCnt(30),vCnt(30),length(edges.size());
      rep(i,edges.size()){
        if(edges[i]%2==0)hCnt[nodes[i].fi/30]++;
        else vCnt[nodes[i].fi%30]++;
      }
      rep(i,edges.size()){
        if(edges[i]%2==0)length[i]=hCnt[nodes[i].fi/30];
        else length[i]=vCnt[nodes[i].fi%30];
      };
      /*rep(i,nodes.size()){
        cout<<"("<<nodes[i].fi/30<<"/"<<nodes[i].fi%30<<")-";
        cout<<"("<<nodes[i].se/30<<"/"<<nodes[i].se%30<<") ";
      }
      cout<<endl;*/
      //outv(length);
      rep(i,nodes.size()){
        ld addWeight=difference*(1/trustInvSum/(g[nodes[i].fi][nodes[i].se].trust+1));
        ld addTrust=1;
        //out(ansPlace[i]/30,ansPlace[i]%30,ansPlace[i+1]/30,ansPlace[i+1]%30,addTrust);
        //addWeight*=alpha;
        addTrust*=sigmoid((ld)length[i]/edges.size(),0.3,0.8,0.8,1.8);
        addTrust*=alpha;
        g[nodes[i].fi][nodes[i].se].weight+=addWeight;
        g[nodes[i].se][nodes[i].fi].weight+=addWeight;
        chmax(g[nodes[i].fi][nodes[i].se].weight,0.1);
        chmax(g[nodes[i].se][nodes[i].fi].weight,0.1);
        g[nodes[i].fi][nodes[i].se].trust+=addTrust;
        g[nodes[i].se][nodes[i].fi].trust+=addTrust;
      }
    };//実測値記録終わり
    bitset<EDGE_NUM> edgesBit;
    rep(i,ansPlace.size()-1)edgesBit.set(nodesToEdge(ansPlace[i],ansPlace[i+1]));
    weightWrite(b,edgesBit);
    /*
    ll end=edgesBitSet.size();
    rep(i,end){
      auto x=edgesBitSet[i];
      auto orBit=x.fi|edgesBit;
      if(orBit!=x.fi && orBit!=edgesBit)continue;
      auto xorBit=x.fi^edgesBit;
      if(!xorBit.any())continue;
      weightWrite(abs(b-x.se),xorBit,parameter);
      edgesBitSet.push_back({xorBit,abs(b-x.se)});
#ifndef ONLINE_JUDGE
      edgesBitSetCnt[loop]++;
#endif
    }
    edgesBitSet.push_back({edgesBit,b});*/
    /*
    if(loop%100t==0 && loop>0){
      sort(all(edgesBitSet),[](auto const& l,auto const& r){
        return l.fi.count()>r.fi.count();
      });
      //out(edgesBitSet.back().fi.count());
      rep(i,edgesBitSet.size()){
        auto x=edgesBitSet[i];
        if(x.fi.count()<15-loop/100)weightWrite(x.se,x.fi,0.5);
      }
    }*/
  }
#ifndef ONLINE_JUDGE
  {
#ifndef RESULT_ONLY
    ll cnt=0;
    each(x,edgesBitSetCnt){
      cnt+=x;
      cerr<<cnt<<" ";
    }
    cerr<<endl;
    ld errorSum=0;
    ll errorCnt=0;
    auto output=[&](ll p1,ll p2){
        if(g[p1][p2].weight==5000)cerr<<"   -";
        else cerr<<setw(4)<<(int)g[p1][p2].weight;
        cerr<<":"<<setw(4)<<(int)g[p1][p2].z()<<"[";
        if(g[p1][p2].trust==0.1)cerr<<"  -";
        else cerr<<setw(3)<<(int)g[p1][p2].trust;
        cerr<<"]";
        errorSum+=(g[p1][p2].z()-gc[p1][p2])*(g[p1][p2].z()-gc[p1][p2])*g[p1][p2].trust;
        errorCnt+=g[p1][p2].trust;
    };
    auto check=[&](ll p1,ll p2){
      auto a=g[p1][p2],b=g[p2][p1];
      if(a.estimated!=b.estimated)return false;
      if(a.weight!=b.weight)return false;
      if(a.trust!=b.trust)return false;
      return true;
    };
    rep(x,30){
      rep(y,30){
        if(x!=0)if(!check(x*30+y,(x-1)*30+y)){
          cerr<<"error :"<<x*30+y<<" "<<(x-1)*30+y<<endl;
          return 1;
        }
      }
      rep(y,30){
        if(y!=0)if(!check(x*30+y,x*30+y-1)){
          cerr<<"error :"<<x*30+y<<" "<<x*30+y-1<<endl;
          return 1;
        }
        cerr<<"       ("<<setw(2)<<x<<"/"<<setw(2)<<y<<") ";
        if(y!=29)output(x*30+y,x*30+y+1);
      }
      cerr<<endl;
      rep(y,30){
        if(x!=29)output(x*30+y,(x+1)*30+y);
        cerr<<"               ";
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