/*
string ver.
*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	long ans=0;
	string s;
	cin>>s;
	long j=0,old=0;
	for(long i=0;s[i]!=0;i++){
		for(j=0;s[i+j]=='A';j++);
		if(j>0 || old>0){
			if(s[i+j]=='B' && s[i+j+1]=='C'){
				ans+=j+old;
				old+=j;
				i+=j+1;
			}else{
				old=0;
				i+=j-1;
			}
		}else{
			old=0;
		}
	}
	printf("%ld",ans);
	return 0;
}
