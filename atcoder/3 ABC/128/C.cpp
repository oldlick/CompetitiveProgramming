#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int sNum,lNum,lPat[10][10]={},lOn[10]={};
	cin>>sNum>>lNum;
	for(int i=0;i<lNum;i++){
		int K;
		cin>>K;
		for(int j=0;j<K;j++){
			int s;
			cin>>s;
			lPat[i][s-1]=1;
		}
	}
	for(int i=0;i<lNum;i++){
		cin>>lOn[i];
	}
	//cout<<endl;//
	int ans=0;
	for(int tmp_s=0;tmp_s<(1<<sNum);tmp_s++){
		//cout<<"< "<<tmp_s<<" >"<<endl;//
		for(int i=0;i<lNum;i++){
			//cout<<"lump "<<i<<endl;//
			int sum=0;
			for(int j=0;j<sNum;j++){
				//cout<<"switch "<<j<<endl;//
				//cout<<((tmp_s>>j)&1)<<" and "<<lPat[i][j]<<endl;//
				if((tmp_s>>j)&1 && lPat[i][j]){
					sum++;
				}
			}
			if((sum&1)!=lOn[i]){
				//cout<<"ONE OFF"<<endl;//
				goto NEXT;
			}else{
				//cout<<"this l is on"<<endl;//
			}
		}
		//cout<<"ALL ON"<<endl;//
		ans++;
		NEXT:;
		//cout<<endl;//
	}
	cout<<ans<<endl;
	return 0;
}
