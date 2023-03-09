#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

void swap1(pair<int,int> *a,pair<int,int> *b){
	pair<int,int> temp=*a;
	*a=*b;
	*b=temp;
}
void sort1(vector<pair<int,int>> &a,int lower,int upper){
	pair<int,int> bound=a[lower];
	int l=lower,u=upper;
	//printf("lower = %d, upper = %d\n",l,u);
	
	do{
		while(a[l]<bound)l++;
		while(a[u]>bound)u--;
		if(l<=u){
			swap1(&a[l],&a[u]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)sort1(a,lower,u);
	if(l<upper)sort1(a,l,upper);
}
int indexMax(vector<pair<int,int>> a,int lim){
	int index=0,max=a[0].second;
	for(int i=1;i<lim;i++){
		if(a[i].second>max){
			index=i;
			max=a[i].second;
		}
	}
	return index;
}
int main(){
	int n,l;
	cin>>n>>l;
	vector<pair<int,int>> dp;
	for(int i=0;i<n;i++){
		pair<int,int> tmp;
		cin>>tmp.first>>tmp.second;
		if(l>=tmp.first){
			dp.push_back(tmp);
		}
	}
	sort1(dp,0,dp.size()-1);
	int ans=0,i=0;
	for(int day=1;day<=l;day++){
		//for(;dp[i].first<=day && i<=dp.size();i++);
		int index=indexMax(dp,i);
		ans+=dp[index].second;
		dp.erase(dp.begin()+index);
		i--;
		/*for(int i=0;i<dp.size();i++){
			cout<<dp[i].first<<dp[i].second<<endl;//
		}*/
	}
	cout<<ans;
	return 0;
}
