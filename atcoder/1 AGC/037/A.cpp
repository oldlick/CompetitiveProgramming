#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	string str;
	cin>>str;
	int l=str.length();
	
	int ans=1;
	char old=str[0];
	for(int i=1;i<l;i++){
		if(old==str[i]){
			i++;
			if(i!=l)ans++;
			old=0;
			//cout<<"double"<<endl;
		}else{
			ans++;
			old=str[i];
			//cout<<str[i]<<endl;
		}
	}
	cout<<ans;
	return 0;
}
