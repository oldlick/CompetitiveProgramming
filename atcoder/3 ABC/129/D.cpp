#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main(){
	int high=0,wide=0;
	cin>>high>>wide;
	char data[2002][2002]={};
	for(int i=0;i<high+2;i++){
		for(int j=0;j<wide+2;j++){
			if(i==0||i==high+1){data[i][j]='#';}
			else if(j==0||j==wide+1){data[i][j]='#';}
			else{cin>>data[i][j];}
		}
	}/*
	for(int i=1;i<=high;i++){
		for(int j=1;j<=wide;j++){
			cout<<data[i][j];
		}
		cout<<endl;
	}*/
	int ans=0;
	for(int i=1;i<=high;i++){
		for(int j=1;j<=wide;j++){
			int tmp=0;
			if(data[i][j]=='#'){continue;}
			int highAdd=1,wideAdd=0;
			for(int k=1;data[i+highAdd*k][j+wideAdd*k]!='#';k++){
				tmp++;
			}
			highAdd=-1,wideAdd=0;
			for(int k=1;data[i+highAdd*k][j+wideAdd*k]!='#';k++){
				tmp++;
			}
			highAdd=0,wideAdd=1;
			for(int k=1;data[i+highAdd*k][j+wideAdd*k]!='#';k++){
				tmp++;
			}
			highAdd=0,wideAdd=-1;
			for(int k=1;data[i+highAdd*k][j+wideAdd*k]!='#';k++){
				tmp++;
			}
			if(ans<tmp){
				ans=tmp;
				//cout<<i<<" "<<j<<" "<<tmp<<endl;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
