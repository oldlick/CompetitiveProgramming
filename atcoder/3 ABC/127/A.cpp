#include <iostream>

int main(){
	int A,B;
	std::cin>>A;
	std::cin>>B;
	if(A<=5){
		B=0;
	}else if(A<=12){
		B/=2;
	}
	std::cout<<B;
	return 0;
}
