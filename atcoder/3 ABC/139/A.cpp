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
	char S[3]={};
	for(int i=0;i<3;i++){
		cin>>S[i];
	}
	int ans=0;
	for(int i=0;i<3;i++){
		char tmp;
		cin>>tmp;
		if(tmp==S[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
