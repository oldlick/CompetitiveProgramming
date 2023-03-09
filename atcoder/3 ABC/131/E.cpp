#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int num=0,taste=0;
	cin>>num>>taste;
	if(taste>=0){
		cout<<(num-1)*taste+((num-1)*num/2);
	}else{
		if((num-1)<=taste*(-1)){
			cout<<(taste*2+num-2)*(num-1)/2;
		}else{
			cout<<num*taste+num*(num-1)/2;
		}
	}
	return 0;
}
