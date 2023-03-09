#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <complex>
#include <regex>
#include <cassert>
#include <functional>

#define Debug cout << "line: " << __LINE__ << "Debug" << endl;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MP make_pair
#define MOD 1000000007
#define PI 3.14159265358979323846
const long long INF=1LL<<60;

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<long long>;

void set_FPD(int n){
    cout << fixed << setprecision(n);
    return;
}

vi dx={-1,0,1,0}, dy={0,1,0,-1};

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}


vi s,t;
int ans=0;

void Main(){
    int n,k;
    cin>>n>>k;
    s.resize(n);
    t.resize(n);
    for(auto &x:s) cin>>x;
    for(auto &x:t) cin>>x;
    for(int i=0;i<k;i++){
        foreach_comb(n-1,i,[](int *indexes){
            vector<deque<int>> vq;
            vq.push_back(deque<int>());
            int cnt=0;
            for(int j=0;j<(int)s.size();j++){
                vq.back().push_back(s[j]);
                if(j==indexes[cnt]){
                    cnt++;
                    vq.push_back(deque<int>());
                }
            }
            priority_queue<pair<int,int>> pq;
            for(int i=0;i<(int)vq.size();i++){
                /*
                cout<<i<<endl;
                for(auto &x:vq[i]){
                    cout<<x<<" ";
                }
                cout<<endl;
                */
                pq.push(make_pair(-vq[i].front(),i));
                vq[i].pop_front();
            }
            vi tmp;
            while(tmp.size()!=t.size()){
                pair<int,int> p=pq.top();
                pq.pop();
                tmp.push_back(-p.first);
                if(!vq[p.second].empty()){
                    pq.push(make_pair(-vq[p.second].front(),p.second));
                    vq[p.second].pop_front();
                }
            }
            /*
            for(auto &x:tmp){
                cout<<x<<" ";
            }
            cout<<endl;
            */
            bool flag=true;
            for(int i=0;i<(int)t.size();i++){
                if(tmp[i]!=t[i]){
                    flag=false;
                }
            }
            if(flag) ans++;
        });
    }
    cout<<ans<<endl;
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
    return 0;
}