#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	int A,B,T;
	cin>>A>>B>>T;
	int div=(T-B)/(B-A);
	if((T-B)%(B-A)!=0) div++;
	cout<<div*(B-A)+B;
}