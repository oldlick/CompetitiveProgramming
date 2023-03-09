#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void swp(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

void quicksort(int a[],int lower,int upper){
	int bound=a[lower],l=lower,u=upper;
	do{
		while(a[l]<bound)l++;
		while(a[u]>bound)u--;
		if(l<=u){
			swp(a[l],a[u]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)quicksort(a,lower,u);
	if(l<upper)quicksort(a,l,upper);
}

int main(){
	int p[100000],num;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>p[i];
	}
	quicksort(p,0,num-1);
	cout<<p[num/2]-p[num/2-1]<<endl;
	return 0;
}
