#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	char num=0,oldNum=0;
	for(int i=0;i<4;i++){
		cin>>num;
		if(num==oldNum){
			cout<<"Bad"<<endl;
			return 0;
		}else{
			oldNum=num;
		}
	}
	cout<<"Good"<<endl;
	return 0;
}
