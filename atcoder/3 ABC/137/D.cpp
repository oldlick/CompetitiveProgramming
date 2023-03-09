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
void sort1(pair<int,int> a[],int lower,int upper){
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
int main(){
	int n,l;
	cin>>n>>l;
	pair<int,int> dp[100000];
	for(int i=0;i<n;i++){
		pair<int,int> tmp;
		cin>>tmp.first>>tmp.second;
		if(l>=tmp.first){
			dp[i].first=tmp.first;
			dp[i].second=tmp.second;
		}else{
			i--;
			n--;
		}
	}
	sort1(dp,0,n-1);
	for(int i=0;i<n;i++){
		cout<<dp[i].first<<dp[i].second<<endl;//
	}
	return 0;
}
