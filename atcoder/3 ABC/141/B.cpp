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
	for(int i=0;i<S.length();i++){
		if(i%2==0){
			if(S[i]=='L')goto No;
		}else{
			if(S[i]=='R')goto No;
		}
	}
	Yes:
	cout<<"Yes";
	return 0;
	No:
	cout<<"No";
	return 0;
}
