#include <cstdio>
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
	vector<string> S(N);
	for(int i=0;i<N;i++) cin>>S[i];
	for(int i=0;i<N;i++){
		auto f1=S[i].find("okyo");
		if(f1>S[i].size()){
			cout<<"No"<<endl;
			continue;
		}
		S[i]=S[i].substr(f1);
		auto f2=S[i].find("ech");
		if(f2>S[i].size()){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
}

