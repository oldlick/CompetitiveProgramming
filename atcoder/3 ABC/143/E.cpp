#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

ll N,M,L;
ll A[45000];
ll B[45000];
ll C[45000];

int main(){
	cin>>N>>M>>L;
	rep(i,M){
		ll a,b,c;
		cin>>a>>b>>c;
		if(c<=L){
			A[i]=a;
			B[i]=b;
			C[i]=c;
		}else{
			i--;
			M--;
		}
	}
	ll Q;
	vector<ll> S(Q);
	vector<ll> T(Q);
	rep(i,M)cin>>S[i]>>T[i];
	
	
	return 0;
}
void count(ll place){
	if(memo[place][0]!=-2)return;
	vector<Town> town(N);
	town[place].oil=0;
	int change=1;
	while(change!=0){
		change=0;
		rep(i,M){
			if(town[A[i]].oil+C[i]<town[B[i]].oil){
				town[B[i]].v=A[i];change++;
			if(town[B[i]].oil+C[i]<town[A[i]].oil){
				town[A[i]].v=B[i];change++;
			}
		}
	}
	rep(i,N){
		rep(j,N){
			memo[place][j]=10;
		}
	}
}
