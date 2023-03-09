#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int ismin(int a[18],int n){
	int min=a[1],p=1;
	for(int i=1;i<n-1;i++){
		if(min>a[i]){
			min=a[i];
			p=i;
		}
	}
	return p;
}
void erase(int a[18],int n){
	for(int i=0;n+i+1<18;i++){
		a[n+i]=a[n+i+1];
	}
}
void show(int a[18],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
}
int main(){
	int a[18]={},n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-2;i++){
		show(a,n);
		cout<<endl;
		int p=ismin(a,n-i);
		cout<<p<<" : ";
		a[p-1]+=a[p];
		a[p+1]+=a[p];
		erase(a,p);
	}
	cout<<a[0]+a[1];
}
