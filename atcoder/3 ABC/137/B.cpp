#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int k,x;
	cin>>k>>x;
	k--;
	for(int i=x-k;i<=x+k;i++){
		cout<<i<<' ';
	}
	return 0;
}
