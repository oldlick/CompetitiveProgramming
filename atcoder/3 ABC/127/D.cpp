#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void quicksort(std::pair<int,int> a[],int lower,int upper){
	std::pair bound=a[lower];
	int l=lower,u=upper;
	do{
		while(a[l]<bound)l++;
		while(a[u]>bound)u--;
		if(l<=u){
			swap(a[l],a[u]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)quicksort(a,lower,u);
	if(l<upper)quicksort(a,l,upper);
}
int main(){
	int N,M;
	std::pair<int,int> cord[100000];
	long ans=0;
	scanf("%d %d",&N,&M);
	//std::cout<<"N"<<N<<"M"<<M<<std::endl;//
	for(int i=0;i<N;i++){
		//std::cout<<i<<" "<<N<<" "<<i<<std::endl;//
		scanf("%d",&cord[i].first);
		cord[i].second=1;
	}
	for(int i=0;i<M;i++){
		//std::cout<<i<<" "<<M<<" "<<N+i<<std::endl;//
		scanf("%d",&cord[N+i].second);
		scanf("%d",&cord[N+i].first);
	}
	quicksort(cord,0,N+M-1);
	int tmp=1;
	for(int i=0;i<N;i++){
		ans+=cord[M+N-tmp].first;
		if(cord[M+N-tmp].second==0){
			tmp++;
		}else{
			cord[M+N-tmp].second--;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}
