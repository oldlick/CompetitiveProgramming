#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	char input1=0,input2=0;
	int num1=0,num2=0;
	for(int i=0;i<4;i++){
		char tmp;
		cin>>tmp;
		if(num1==0){
			input1=tmp;
			num1++;
		}else if(input1==tmp){
			num1++;
		}else if(num2==0){
			input2=tmp;
			num2++;
		}else if(input2==tmp){
			num2++;
		}
	}
	if(num1==2 && num2==2){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
