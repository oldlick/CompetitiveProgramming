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
	vector<int> v;
	double ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ans=v[0];
	for(int i=1;i<n;i++){
		ans+=v[i];
		ans=ans/2;
	}
	cout<<ans;
	return 0;
}
