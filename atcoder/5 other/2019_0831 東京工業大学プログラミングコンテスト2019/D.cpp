#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long
 
void fill(vector<bool> &isP){
	int size=isP.size()-1;
	int end=sqrt(size);
	isP[0]=0;isP[1]=0;
	for(int i=2;i<=end;i++){
		if(isP[i]==1){
			for(int j=i*2;j<=size;j+=i){
				isP[j]=0;
			}
		}
	}
}
void xch(vector<int> X , vector<bool> isP , int num[4]){
	for(int i=0;i<X.size();i++){
		if(X[i]==7){
			num[3]++;
		}else if(isP[X[i]-2]==1){
			num[2]++;
		}else{
			num[1]++;
		}
	}
}
int main(){
	int N;
	cin>>N;
	vector<int> X(N);
	int max=0;
	for(int i=0;i<N;i++){
		cin>>X[i];
		if(max<X[i])max=X[i];
	}
	vector<bool> isP(max+1,1);
	fill(isP);
	/*for(int i=1;i<=max;i++){
		cout<<i<<":"<<isP[i]<<endl;
	}*/
	int num[4]={};
	xch(X,isP,num);
	/*for(int i=1;i<=3;i++){
		cout<<i<<":"<<num[i]<<endl;
	}*/
	
	if(num[3]%2==0){
		N-=num[3];
		if(N%2==1)goto M;
		if(num[1]%2==1)goto M;
		goto B;
	}else{
		N-=num[3];
		N+=1;
		if(N%2==0)goto M;
		if(num[1]%2==0)goto M;
		goto B;
	}
	
	M:
	cout<<"An"<<endl;
	return 0;
	B:
	cout<<"Ai"<<endl;
	return 0;
}
