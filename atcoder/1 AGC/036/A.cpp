#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define ll long long
using namespace std;

#include <math.h> 

double Abs(double a){
	if(a<0){
		return a*(-1);
	}else{
		return a;
	}
}
ll tri(ll x1,ll y1,ll x2,ll y2){
	return ((y1-y2)*x2+(x2-x1)*y2)/2;
}
int main(){
	long long s=0;
	cin>>s;
	long long def=sqrt(s);
	long long x1=0,y1=0;
	long long x2=0,y2=0;
	long long x3=0,y3=0;
	if(def*def!=s){
		def++;
		x2=1;
		y3=def*def-s;
	}
	y2=def;
	x3=def;
	cout<<x1<<' ';//x1
	cout<<y1<<' ';//y1
	cout<<x2<<' ';//x2
	cout<<y2<<' ';//y2
	cout<<x3<<' ';//x3
	cout<<y3<<endl;//y3
	//printf("%lld",tri(x2,y2,x3,y3));
	return 0;
}