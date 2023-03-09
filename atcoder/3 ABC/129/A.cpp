#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int sum=0,max=0;
	for(int i=0;i<3;i++){
		int tmp;
		cin>>tmp;
		sum+=tmp;
		if(max<tmp){max=tmp;}
	}
	cout<<sum-max;
	return 0;
}
