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
	ll mul=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mul*=a[i];
	}
	ll add=0;
	for(int i=0;i<n;i++){
		add+=mul/a[i];
	}
	cout<<(double)mul/add;
	return 0;
}
