#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	string S;
	cin>>S;
	if(S[0]=='S'){
		S="Cloudy";
	}else if(S[0]=='C'){
		S="Rainy";
	}else{
		S="Sunny";
	}
	cout<<S;
	return 0;
}