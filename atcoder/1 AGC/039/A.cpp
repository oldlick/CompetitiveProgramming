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
	char S[110];
	ll K,N,dNum=0,num=0;
	cin>>S>>K;
	for(N=0;S[N]!='\0';N++);
	ll tmp=1;
	rep(i,N){
		if(S[i]==S[i+1]){
			tmp++;
		}else{
			if(tmp==N){
				cout<<N*K/2;
				return 0;	
			}
			num+=tmp/2;
			tmp=1;
		}
	}
	ll R=0,L=0;
	if(S[0]==S[N-1]){
		rep(i,N){
			if(S[i]==S[i+1]){
				tmp++;
			}else{
				R+=tmp;
				tmp=1;
				break;
			}
		}
		rep(i,N){
			if(S[N-1-i]==S[N-1-i-1]){
				tmp++;
			}else{
				L+=tmp;
				tmp=1;
				break;
			}
		}
	}
	dNum=(L+R)/2-L/2-R/2;
	/*
	cout<<num<<endl;
	cout<<R<<endl;
	cout<<L<<endl;
	cout<<dNum<<endl;
	*/
	cout<<num*K+dNum*(K-1)<<endl;
	return 0;
}
