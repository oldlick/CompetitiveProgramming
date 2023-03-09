#include <iostream>
#include <cstring>
using namespace std;

void swp_i(int* N1,int* N2){
	int tmp=*N1;
	*N1=*N2;
	*N2=tmp;
}
void swp_c(char* S1,char* S2){
	char tmp[11];
	strcpy(tmp,S1);
	strcpy(S1,S2);
	strcpy(S2,tmp);
}
int main(){
	int N;
	cin>>N;
	char S[100][11];
	int P[100],NUM[100];
	for(int i=0;i<N;i++){
		cin>>S[i]>>P[i];
		NUM[i]=i;
	}
	for(int i=N;i>0;i--){
		for(int j=0;j<i-1;j++){
			if(strcmp(S[j],S[j+1])>0){
				swp_c(S[j],S[j+1]);
				swp_i(&P[j],&P[j+1]);
				swp_i(&NUM[j],&NUM[j+1]);
			}else if(strcmp(S[j],S[j+1])==0){
				if(P[j]<P[j+1]){
					swp_c(S[j],S[j+1]);
					swp_i(&P[j],&P[j+1]);
					swp_i(&NUM[j],&NUM[j+1]);
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<NUM[i]+1<<endl;
	}
	return 0;
}
