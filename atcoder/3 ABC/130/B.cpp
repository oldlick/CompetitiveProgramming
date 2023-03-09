#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n=0,x=0,d=0,l=0,ans=0;
	cin>>n>>x;
	for(int i=0;i<=n && d<=x;i++){
		ans++;
		cin>>l;
		d+=l;
	}
	cout<<ans;
	return 0;
}