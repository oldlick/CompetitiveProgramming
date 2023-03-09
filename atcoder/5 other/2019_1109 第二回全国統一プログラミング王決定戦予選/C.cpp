#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}	
int main(){
	int N;
	cin>>N;
	/*vector<pair<int,int>> AB(N);
	REP(i,N) cin>>AB[i].first;
	REP(i,N) cin>>AB[i].second;
	sort(AB.begin(),AB.end());*/
	vector<int> A(N);
	vector<pair<int,int>> AB(N);
	REP(i,N){
		cin>>A[i];
		AB[i].second=A[i];
	}
	REP(i,N){
		cin>>AB[i].first;
	}
	sort(A.begin(),A.end());
	sort(AB.begin(),AB.end());
	REP(i,N){
		if(A[i]>AB[i].second){
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"No";
	return 0;
	OK:
	cout<<"Yes";
	return 0;
}