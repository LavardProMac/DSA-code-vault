11 AC r
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 3500000
const ll mod=1e9+7;
ll t,n,l,r,k,b,c[10001],sum1,sum2,a[501],pri[1001],len=0;
string s;
ll binpow(ll o,ll p){
    ll tich=1;
    ll m=2024;
    for(;p>0;o=(o*o)%m,p/=2){
        if(p%2==1){
            tich=(tich*o)%m;
        }
    }
    return tich;
}
void tsnt(ll oo,ll ad){
    ll x=oo;
    for(int ii=2;ii<=sqrt(x);ii++){
        while(oo%ii==0){
            oo/=ii;
            pri[ii]+=ad;
        }
    }
    if(oo>1){
        pri[oo]+=ad;
    }
}
ll nCr(ll n,ll r){
    if(r<0 or r>n){
        return 0;
    }
    ll tich=1;
    for(int i=n-r+1;i<=n;i++){
        tsnt(i,1);
    }
     for(int i=1;i<=r;i++){
        tsnt(i,-1);
    }
    for(int i=2;i<=1000;i++){
        tich*=binpow(i,pri[i]);
        tich%=2024;
        pri[i]=0;
    }
    return tich;
}
int main() {
    ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
        cin>>n>>k;
        len=0;
        for(int i=1;i<=k;i++){
            cin>>a[i];
            len+=a[i]+1;
        }
        len=max(len-1,(ll)0);
        if(k==0){
            cout<<1<<'\n';
        }
        else{
            cout<<nCr(n-len+k,k)<<'\n';
        }
   }
}
