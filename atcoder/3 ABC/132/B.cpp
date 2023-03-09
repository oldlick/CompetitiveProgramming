#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

bool cheak(int a,int b,int c){
	if(a<b && b<c){
		return 1;
	}else if(a>b && b>c){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int p[20],num,ans;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>p[i];
	}
	for(int i=1;i<num-1;i++){
		if(cheak(p[i-1],p[i],p[i+1]))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
