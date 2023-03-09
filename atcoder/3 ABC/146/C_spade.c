#include <stdio.h>
int ten(int a){
	int i,b=1;
	for(i=2;i<=a;i++){
		b*=10;
	}
	return b;
}
int main(void){
	long long int a,b,x;
	int i,j;
	scanf("%lld",&a);
	scanf("%lld",&b);
	scanf("%lld",&x);
	for(i=1;i<=10;i++){
		if(x<ten(i)*a+i*b){//i-1桁確定
			break;
		}
	}
	//printf("%d\n",i-1);
	
	for(j=ten(i)-1;j>=ten(i-1);j--){
		if(x>=a*j+b*(i-1)){
			printf("%d\n",j);
			return 0;
		}
	}
	printf("%d",0);
	return 0;
}