#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;


#include <stdio.h>
void quicksort(int a[],int lower,int upper);
void swap(int *a,int *b);
void printArray(int a[],int n);

void quicksort(pair<int,int> a[],int lower,int upper){
	int bound=a[lower].second,l=lower,u=upper;
	do{
		while(a[l].second<bound)l++;
		while(a[u].second>bound)u--;
		if(l<=u){
			a[u].swap(a[l]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)quicksort(a,lower,u);
	if(l<upper)quicksort(a,l,upper);
}

int main(){
	int num=0;
	pair<int,int> time[200000]={};
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>time[i].first>>time[i].second;
	}
	quicksort(time,0,num-1);
	long sum=0;
	for(int i=0;i<num;i++){
		sum+=time[i].first;
		if(sum>time[i].second){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
