#include <cstdio>
#include <iostream>
using namespace std;

int canMove(char road[],int s,int g){
	char oldRock='.';
	for(int i=s;i<g;i++){
		if(oldRock=='#' && road[i]=='#')return 0;
		oldRock=road[i];
	}
	return 1;
}
int canMoveA(char road[],int Bs,int Bg){
	for(int i=Bs;i<=Bg;i++){
		if(road[i-1]=='.' && road[i]=='.' && road[i+1]=='.'){
			return 1;
		}
	}
	return 0;
}

int main(){
	int num,As,Bs,Ag,Bg;
	char road[200000];
	cin>>num>>As>>Bs>>Ag>>Bg;
	As--;Ag--;Bs--;Bg--;
	cin>>road;
	if(Ag<Bg){
		if(canMove(road,As,Ag)==1 && canMove(road,Bs,Bg)==1){
			printf("Yes");
		}else{
			printf("No");
		}
	}else{
		if(canMove(road,Bs,Bg)==1 && canMove(road,As,Ag)==1 && canMoveA(road,Bs,Bg)==1){
			printf("Yes");
		}else{
			printf("No");
		}
	}
	return 0;
}
