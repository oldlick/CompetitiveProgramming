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


int costCheck(vector<pair<pair<ll,ll>,double>> &load,vector<pair<double,ll>> &nord);
ll N,M;
vector<pair<pair<ll,ll>,double>> load;
vector<pair<double,ll>> nord;


int main(){
	cin>>N>>M;
	load.resize(M);
	nord.resize(N);
	REP(i,M){
		ll tmp1,tmp2;
		cin>>tmp1>>tmp2;
		load[i].first.first=tmp2-1;
		load[i].first.second=tmp1-1;
	}
	sort(load.begin(),load.end(),greater<pair<pair<ll,ll>,double>>());
	int idx=costCheck(load,nord);
	if(load.size()==nord[0].first){
		//cout<<"no cut"<<endl;
	}else{
		load.erase(load.begin()+idx);
		nord.clear();
		nord.resize(N);
		costCheck(load,nord);
	}
	printf("%.10lf",nord[0].first);
	return 0;
}
int costCheck(vector<pair<pair<ll,ll>,double>> &load,vector<pair<double,ll>> &nord){
	ll old=N-1;
	REP(i,load.size()){
		if(load[i].first.first!=old){
			old=load[i].first.first;
			nord[load[i].first.first].first/=nord[load[i].first.first].second;
		}
		load[i].second=nord[load[i].first.first].first+1;
		nord[load[i].first.second].first+=nord[load[i].first.first].first+1;
		nord[load[i].first.second].second++;
		/*cout<<load[i].first.second<<"->"<<load[i].first.first<<endl;
		REP(i,nord.size()){
			cout<<nord[i].first<<":"<<nord[i].second<<endl;
		}*/
	}
	nord[0].first/=nord[0].second;
	/*REP(i,nord.size()){
		cout<<nord[i].first<<":"<<nord[i].second<<endl;
	}
	REP(i,load.size()){
		cout<<load[i].first.second<<"->"<<load[i].first.first<<":"<<load[i].second<<endl;
	}*/
	int max=load[0].second,max_idx=0;
	REP(i,M){
		if(max<load[i].second){
			max=load[i].second;
			max_idx=i;
		}
	}
	//cout<<max_idx<<" erase"<<endl;
	return max_idx;
}
