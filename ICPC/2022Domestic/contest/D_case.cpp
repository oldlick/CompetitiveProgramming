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
#include <random>

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

void Main(){
    int n;
    cin>>n;
    mt19937 mt{random_device{}()};
    uniform_int_distribution<int> dist(1,n);

    cout<<n<<" "<<dist(mt)<<endl;
    {
        vi tmp(n+1,0);
        tmp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            while(tmp[cnt]!=0){
                cnt=dist(mt);
            }
            cout<<cnt<<" ";
            tmp[cnt]=1;
        }
        cout<<endl;
    }
    {
        vi tmp(n+1,0);
        tmp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            while(tmp[cnt]!=0){
                cnt=dist(mt);
            }
            cout<<cnt<<" ";
            tmp[cnt]=1;
        }
        cout<<endl;
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
    return 0;
}