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
	int N;
	cin>>N;
	int maxN=0;
	int nowN=0;
	int oldH=0;
	int nowH=0;
	for(int i=0;i<N;i++){
		cin>>nowH;
		if(nowH<=oldH){
			nowN++;
		}else{
			if(nowN>maxN)maxN=nowN;
			nowN=0;
		}
		oldH=nowH;
		//cout<<" "<<nowN<<endl;
	}
	if(nowN>maxN)maxN=nowN;
	cout<<maxN;
	return 0;
}
