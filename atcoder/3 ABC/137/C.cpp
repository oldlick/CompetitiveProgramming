#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

void swap1(string *a,string *b){
	string temp=*a;
	*a=*b;
	*b=temp;
}
void sort1(string a[],int lower,int upper){
	 string bound=a[lower];
	 int l=lower,u=upper;
	//printf("lower = %d, upper = %d\n",l,u);
	
	do{
		while(a[l]<bound)l++;
		while(a[u]>bound)u--;
		if(l<=u){
			swap1(&a[l],&a[u]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)sort1(a,lower,u);
	if(l<upper)sort1(a,l,upper);
}
int main(){
	string s[100000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		//cout<<s[i]<<endl;//
	}
	sort1(s,0,n-1);
	for(int i=0;i<n;i++){
		//cout<<s[i]<<endl;//
	}
	ll cnt=0;
	ll ans=0;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			cnt++;
			ans+=cnt;
			//cout<<"yes!"<<endl;//
		}else{
			cnt=0;
		}
	}
	cout<<ans;
	
	return 0;
}
