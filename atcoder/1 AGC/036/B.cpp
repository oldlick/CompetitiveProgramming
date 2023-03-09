#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define ll long long
using namespace std;

void add(vector<int> &ans,vector<int> a){
	for(int i=0;i<a.size();i++){
		int j=ans.size()-1;
		while(j>=0 && ans[j]!=a[i])j--;
		if(j==-1){
			ans.push_back(a[i]);
		}else{
			ans.resize(j);
		}
	}
}
int main(){
	int N,K;
	vector<int> a,ans;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	for(int i=0;i<K;i++){
		add(ans,a);
		if()
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
