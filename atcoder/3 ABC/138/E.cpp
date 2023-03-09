#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	string s,t;
	cin>>s>>t;
	ll ans=0;
	auto old=s.begin();
	auto now=s.begin();
	for(int i=0;i<t.size();i++){
		now=find(old,s.end(),t[i]);
		if(now==s.end()){
			if(old==s.begin()){
				cout<<"-1";
				return 0;
			}else{
				i--;
				old=s.begin();
				ans++;
			}
		}else{
			old=now+1;
		}
	}
	ans*=s.size();
	ans+=now-s.begin()+1;
	cout<<ans;
	return 0;
}
