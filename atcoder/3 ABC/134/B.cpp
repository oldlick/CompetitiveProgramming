#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int num=0,d=0,ans=0;
	cin>>num>>d;
	ans=num/(2*d+1);
	if(num%(2*d+1)!=0){
		ans++;
	}
	cout<<ans;
	return 0;
}