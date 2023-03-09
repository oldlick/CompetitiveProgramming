#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	ll A,B;
	cin>>A>>B;
	if(A-B*2<0){
		cout<<0;
	}else{
		cout<<A-B*2;
	}
	return 0;
}
