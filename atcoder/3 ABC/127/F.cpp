#include <iostream>

int main(){
	int Q,A[200000]={},p_A;
	long B=0;
	std::cin>>Q;
	for(int i=0;i<Q;i++){
		int input;
		std::cin>>input;
		if(input==1){
			int a,b;
			std::cin>>a;
			std::cin>>b;
			if(p_A!=0){
				if(a<A[(p_A-1)/2]){
					b+=A[(p_A-1)/2]-a;
				}else if(A[p_A/2]<a){
					b+=a-A[(p_A)/2];
				}
			}
			int i=0;
			while(i<p_A && A[i]<a)i++;
			int j=p_A;
			while(j>i){
				A[j]=A[j-1];
				j--;
			}
			p_A++;
			A[i]=a;
			B+=b;
		}else{
			std::cout<<A[(p_A-1)/2]<<" "<<B<<std::endl;
		}
	}
}
