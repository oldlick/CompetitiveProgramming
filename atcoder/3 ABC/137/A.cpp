#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int a,b,max;
	cin>>a>>b;
	max=a+b;
	if(max<a-b){
		max=a-b;
	}
	if(max<a*b){
		max=a*b;
	}
	cout<<max;
	return 0;
}
