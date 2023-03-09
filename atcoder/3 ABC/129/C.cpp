#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int num=0,m=0;
	vector<int> broken;
	cin>>num>>m;
	int old=-1;
	broken.push_back(-1);
	for(int i=0;i<m;i++){
		int tmp;
		cin>>tmp;
		broken.push_back(tmp);
		if(tmp==old+1){
			cout<<0;
			return 0;
		}else{
			old=tmp;
		}
	}
	broken.push_back(num+1);
	long data[100002]={0,1};
	for(int i=2;i<100002;i++){
		data[i]=(data[i-1]+data[i-2])%1000000007;
	}
	long ans=1;
	for(int i=1;i<broken.size();i++){
		ans*=data[broken[i]-broken[i-1]-1];
		ans%=1000000007;
	}
	cout<<ans;
	return 0;
}
