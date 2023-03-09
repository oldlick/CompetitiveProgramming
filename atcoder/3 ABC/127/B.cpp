#include <iostream>

int main(){
	int r,D,x;
	std::cin>>r;
	std::cin>>D;
	std::cin>>x;
	for(int i=1;i<=10;i++){
		x=r*x-D;
		std::cout<<x<<std::endl;
	}
	return 0;
}
