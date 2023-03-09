#include <iostream>

int main(){
	int N,M,L,R,l,r;
	std::cin>>N;
	std::cin>>M;
	l=1;r=N;
	for(int i=0;i<M;i++){
		std::cin>>L;
		std::cin>>R;
		if(l<L){
			l=L;
		}
		if(r>R){
			r=R;
		}
	}
	if(l<=r){
		std::cout<<r-l+1<<std::endl;
	}else{
		std::cout<<0<<std::endl;
	}
	return 0;
}
