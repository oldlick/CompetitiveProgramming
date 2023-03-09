#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	long n=0,k=0,end=0,a[100000]={};
	long ans=0,sum=0;
	cin>>n>>k;
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
