#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

int numbering(ll p[200],int point);

ll N;
ll S[200][200]={};
ll P[200]={1};

int main(){
	cin>>N;
	rep(i,N){
		char tmp[300];
		cin>>tmp;
		rep(j,N){
			S[i][j]=tmp[j]-'0';
		}
	}/*
	rep(i,N){
		rep(j,N){
			cout<<S[i][j];
		}
		cout<<endl;
	}*/
	if(numbering(P,0)==-1){
		cout<<-1<<endl;
		return 0;
	}
	ll max=0;
	rep(i,N){
		//cout<<"["<<P[i]<<"]"<<endl;
		if(max<P[i]) max=P[i];
	}
	ll s_max=0;
	rep(i,N){
		if(P[i]==max){
			//cout<<i<<" :"<<endl;
			ll tmp[200]={};
			tmp[i]=1;
			numbering(tmp,i);
			rep(j,N){
				//cout<<"  ["<<tmp[j]<<"]"<<endl;
				if(s_max<tmp[j])s_max=tmp[j];
			}
		}
	}
	cout<<s_max;
	return 0;
}

int numbering(ll p[200],int point){
	rep(i,N){
		if(S[point][i]==1){
			if(p[i]==0){
				p[i]=p[point]+1;
				if(numbering(p,i)==-1)return -1;
			}else if(p[i]%2==p[point]%2){
				//cout<<"oo"<<i<<"ii"<<point<<endl;
				return -1;
			}else{
				if(p[i]>p[point]+1){
					p[i]=p[point]+1;
					if(numbering(p,i)==-1)return -1;
				}
			}
		}
	}
	return 0;
}

/*
01234567890
000000001000
001000100000
010100000000
001010000000
000101000000
000010000000
110001010000
010000000000
100000010101
000000001010
000000000101
000000001010
*/
