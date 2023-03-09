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

int main(){
	int H,W,A,B;
	cin>>H>>W>>A>>B;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int tmp=1;
			if(j<A)tmp^=1;
			if(i<B)tmp^=1;
			cout<<tmp;
		}
		cout<<endl;
	}
	return 0;
}
