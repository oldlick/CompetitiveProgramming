#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	pair<int,int>x[100000]={};
	pair<int,int>y[100000]={};
	pair<int,int>d[100000]={};
	int right,left,up,down;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		if(sum>=k){
			while(sum-a[end]>=k){
				sum-=a[end];
				end++;
			}
			ans+=end+1;
		}
	}
	cout<<ans;
	return 0;
}
