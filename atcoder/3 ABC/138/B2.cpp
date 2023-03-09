#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	int n;
	int a[100]={};
	double ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=(double)1/a[i];
	}
	cout<<1/ans;
	return 0;
}
