#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int num,cnt;
	cin>>num;
	for(int i=1;i<=num;i++){
		int tmp;
		cin>>tmp;
		if(tmp!=i)cnt++;
	}
	if(cnt<=2){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}
