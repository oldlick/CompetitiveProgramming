#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	string s;
	int a;
	cin>>a>>s;
	if(a>=3200){
		cout<<s;
	}else{
		cout<<"red";
	}
	return 0;
}