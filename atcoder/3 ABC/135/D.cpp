#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	char s[100001]={},a[100001]={};
	cin>>s;
	int num=0;
	while(s[num]!=0){
		num++;
	}
	for(int i=0;i<num;i++){
		a[i]=s[num-i-1];
	}
	int sum[3]={},hte[3]={};
	sum[0]+=8;
	for(int i=0;i<num;i++){
		if(a[i]=='?')hte[i%3]++;
		else sum[i%3]+=(a[i]-'0')*(((i/3)%2==0)*2-1);
	}
	if(sum[2]<0){
		sum[2]*=(-1);
		sum[1]*=(-1);
		sum[0]*=(-1);
	}
	while(sum[1]<0){
		sum[2]--;
		sum[1]+=10;
	}
	while(sum[0]<0){
		sum[1]--;
		sum[0]+=10;
	}
	sum[1]+=sum[0]/10;
	sum[0]%=10;
	sum[2]+=sum[1]/10;
	sum[1]%=10;
	sum[2]%=13;
	cout<<sum[2]<<sum[1]<<sum[0];
	return 0;
}
