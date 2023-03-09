#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;

void up(ll &x,ll a){
    x=x*(100+a)/100;
}

bool down(ll &x,ll a){
    ll upper=ceil((double)(x+1)*100/(100+a))-1;
    ll lower=ceil((double)x*100/(100+a));
    if(upper<lower)return false;
    if(upper>lower){
        //printf("convert %lld-> %lld~%lld\n",x,lower,upper);
        return false;
    }
    x=upper;
    return true;
}

bool solve(){
    ll a,b,s;
    cin>>a>>b>>s;
    if(a==0)return false;
    ll max=0;
    for(ll t1=1;t1<s;t1++){
        ll t1_=t1;
        up(t1_,a);
        ll t2_=s-t1_;
        if(t2_<1)continue;
        ll t2=t2_;
        if(!down(t2,a))continue;
        ll t1__=t1;
        ll t2__=t2;
        up(t1__,b);
        up(t2__,b);
        ll s__=t2__+t1__;
        if(max<s__){
            //printf("%lld(%lld),%lld(%lld) -> %lld\n",t1,t1_,t2,t2_,s__);
            max=s__;
        }
    }
    printf("%lld\n",max);
    return true;
}

int main(){
    while(solve());
    return 0;
}