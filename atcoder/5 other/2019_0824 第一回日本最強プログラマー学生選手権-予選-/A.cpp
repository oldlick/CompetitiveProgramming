#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
	int m,d,ans=0;
	cin>>m>>d;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++){
			int d1=j%10;
			//cout<<d1;//
			int d10=(j/10)%10;
			//cout<<d10;//
			if(d1>=2 && d10>=2 && d1*d10==i){
				//cout<<"OK";//
				ans++;
			}
			//cout<<endl;//
		}
	}
	cout<<ans;
	return 0;
}
