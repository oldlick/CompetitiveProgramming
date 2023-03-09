#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n=0,m=0,s[2000]={},t[2000]={};
	int ans;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		int num=0;int k=0;
		for(int j=i;j<n;j++){
			while(s[j]!=t[k])k++;
			if(s[j]!=t[k])break;
			num++;
			k++;
		}
		ans+=(num+1)*num/2;
		ans%=1000000007;
	}
	cout<<ans;
	return 0;
}
