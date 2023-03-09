#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int No(){
	cout<<"No";
	return 0;
}
int Yes(){
	cout<<"Yes";
	return 0;
}
int main(){
	int a[3][2]={},n;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		for(int j=0;j<=3;j++){
			if(j==3){
				return No();
			}
			if(a[j][1]==0){
				a[j][0]=tmp;
				a[j][1]++;
				break;
			}else if(a[j][0]==tmp){
				a[j][1]++;
				break;
			}
		}
	}
	if(a[2][1]!=0){//
		if(a[0][1]!=a[1][1])return No();
		if(a[1][1]!=a[2][1])return No();
		if((a[0][0]^a[1][0])!=a[2][0])return No();
		return Yes();
	}else if(a[1][1]!=0){
		if(a[0][0]==0){
			if(a[0][1]*2!=a[1][1])return No();
			return Yes();
		}
		if(a[1][0]==0){
			if(a[1][1]*2!=a[0][1])return No();
			return Yes();
		}
		return No();
	}else if(a[0][1]!=0){//
		if(a[0][0]!=0)return No();
		return Yes();
	}
}