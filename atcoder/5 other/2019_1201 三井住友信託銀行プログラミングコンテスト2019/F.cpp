#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll a[2],b[2],t[2];
	cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
	REP(i,2){
		a[i]=a[i]*t[i];
		b[i]=b[i]*t[i];
	}
	REP(i,2){
		if(a[i]<b[i]){
			b[i]-=a[i];
			a[i]=0;
		}else{
			a[i]-=b[i];
			b[i]=0;
		}
	}	
	ll A=0,B=0;
	ll cnt=0;
	while(1){
		REP(i,2){
			if(A<B){
				if(A+a[i]>=B+b[i]){
					cnt++;
				}
			}else if(A>B){
				if(A+a[i]<=B+b[i]){
					cnt++;
				}
			}
			A+=a[i];
			B+=b[i];
			if(A>B){
				A-=B;
				B=0;
			}else{
				B-=A;
				A=0;
			}
			//cout<<A<<"/"<<B<<"//"<<cnt<<endl;//
		}
		if(A<B){
			if(A+a[0]+a[1]<=B){
				break;
			}
		}else if(A>B){
			if(A>=B+b[0]+b[1]){
				break;
			}
		}else{
			cout<<"infinity"<<endl;
			return 0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
