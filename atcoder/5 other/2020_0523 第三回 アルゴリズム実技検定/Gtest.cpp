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
#define each(x,v) for(auto& x : v)
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
    cout<<0<<" "<<3<<endl;
    FOR(i,1,201){
        cout<<i<<" "<<3<<endl;
        cout<<-i<<" "<<3<<endl;
    }
	return 0;
}
/*
0 3
1 3
-1 3
2 3
-2 3
3 3
-3 3
4 3
-4 3
5 3
-5 3
6 3
-6 3
7 3
-7 3
8 3
-8 3
9 3
-9 3
10 3
-10 3
11 3
-11 3
12 3
-12 3
13 3
-13 3
14 3
-14 3
15 3
-15 3
16 3
-16 3
17 3
-17 3
18 3
-18 3
19 3
-19 3
20 3
-20 3
21 3
-21 3
22 3
-22 3
23 3
-23 3
24 3
-24 3
25 3
-25 3
26 3
-26 3
27 3
-27 3
28 3
-28 3
29 3
-29 3
30 3
-30 3
31 3
-31 3
32 3
-32 3
33 3
-33 3
34 3
-34 3
35 3
-35 3
36 3
-36 3
37 3
-37 3
38 3
-38 3
39 3
-39 3
40 3
-40 3
41 3
-41 3
42 3
-42 3
43 3
-43 3
44 3
-44 3
45 3
-45 3
46 3
-46 3
47 3
-47 3
48 3
-48 3
49 3
-49 3
50 3
-50 3
51 3
-51 3
52 3
-52 3
53 3
-53 3
54 3
-54 3
55 3
-55 3
56 3
-56 3
57 3
-57 3
58 3
-58 3
59 3
-59 3
60 3
-60 3
61 3
-61 3
62 3
-62 3
63 3
-63 3
64 3
-64 3
65 3
-65 3
66 3
-66 3
67 3
-67 3
68 3
-68 3
69 3
-69 3
70 3
-70 3
71 3
-71 3
72 3
-72 3
73 3
-73 3
74 3
-74 3
75 3
-75 3
76 3
-76 3
77 3
-77 3
78 3
-78 3
79 3
-79 3
80 3
-80 3
81 3
-81 3
82 3
-82 3
83 3
-83 3
84 3
-84 3
85 3
-85 3
86 3
-86 3
87 3
-87 3
88 3
-88 3
89 3
-89 3
90 3
-90 3
91 3
-91 3
92 3
-92 3
93 3
-93 3
94 3
-94 3
95 3
-95 3
96 3
-96 3
97 3
-97 3
98 3
-98 3
99 3
-99 3
100 3
-100 3
101 3
-101 3
102 3
-102 3
103 3
-103 3
104 3
-104 3
105 3
-105 3
106 3
-106 3
107 3
-107 3
108 3
-108 3
109 3
-109 3
110 3
-110 3
111 3
-111 3
112 3
-112 3
113 3
-113 3
114 3
-114 3
115 3
-115 3
116 3
-116 3
117 3
-117 3
118 3
-118 3
119 3
-119 3
120 3
-120 3
121 3
-121 3
122 3
-122 3
123 3
-123 3
124 3
-124 3
125 3
-125 3
126 3
-126 3
127 3
-127 3
128 3
-128 3
129 3
-129 3
130 3
-130 3
131 3
-131 3
132 3
-132 3
133 3
-133 3
134 3
-134 3
135 3
-135 3
136 3
-136 3
137 3
-137 3
138 3
-138 3
139 3
-139 3
140 3
-140 3
141 3
-141 3
142 3
-142 3
143 3
-143 3
144 3
-144 3
145 3
-145 3
146 3
-146 3
147 3
-147 3
148 3
-148 3
149 3
-149 3
150 3
-150 3
151 3
-151 3
152 3
-152 3
153 3
-153 3
154 3
-154 3
155 3
-155 3
156 3
-156 3
157 3
-157 3
158 3
-158 3
159 3
-159 3
160 3
-160 3
161 3
-161 3
162 3
-162 3
163 3
-163 3
164 3
-164 3
165 3
-165 3
166 3
-166 3
167 3
-167 3
168 3
-168 3
169 3
-169 3
170 3
-170 3
171 3
-171 3
172 3
-172 3
173 3
-173 3
174 3
-174 3
175 3
-175 3
176 3
-176 3
177 3
-177 3
178 3
-178 3
179 3
-179 3
180 3
-180 3
181 3
-181 3
182 3
-182 3
183 3
-183 3
184 3
-184 3
185 3
-185 3
186 3
-186 3
187 3
-187 3
188 3
-188 3
189 3
-189 3
190 3
-190 3
191 3
-191 3
192 3
-192 3
193 3
-193 3
194 3
-194 3
195 3
-195 3
196 3
-196 3
197 3
-197 3
198 3
-198 3
199 3
-199 3
200 3
-200 3
*/