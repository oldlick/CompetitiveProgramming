#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int w=0,h=0,x=0,y=0;
	cin>>w>>h>>x>>y;
	printf("%f ",(double)w*h/2);
	if(x*2==w && y*2==h){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
