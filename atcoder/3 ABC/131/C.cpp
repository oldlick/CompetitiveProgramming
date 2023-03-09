#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int gcd(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(b!=0);
	return a;
}

int main(){
	long min,max,div1,div2,lcm;
	cin>>min>>max>>div1>>div2;
	min--;lcm=div1/gcd(div1,div2)*div2;
	long maxNum,minNum;
	maxNum=max-(max/div1+max/div2-max/lcm);
	minNum=min-(min/div1+min/div2-min/lcm);
	cout<<maxNum-minNum<<endl;
	return 0;
}
