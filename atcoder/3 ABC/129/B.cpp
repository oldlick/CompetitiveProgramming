#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int abs(int a){
	if(a<0){
		a*=-1;
	}
	return a;
}

int main(){
	int num=0;
	vector<int> weight;
	cin>>num;
	for(int i=0;i<num;i++){
		int tmp;
		cin>>tmp;
		weight.push_back(tmp);
	}
	int min=-1;
	for(int i=0;i<weight.size();i++){
		int left=0,right=0;
		for(int j=0;j<i;j++){
			left+=weight[j];
		}
		for(int j=i;j<weight.size();j++){
			right+=weight[j];
		}
		if(min>abs(left-right) || min==-1){
			min=abs(left-right);
		}
	}
	cout<<min;
	return 0;
}
