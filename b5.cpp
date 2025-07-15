#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7, N=1e5+5;
ll f[N], a[N];

inline ll mu(ll a, ll b, ll r=1){
    while(b){
        if(b&1) r=r*a%M;
        a=a*a%M, b>>=1;
    }return r;
}
inline void tienxuly(){ f[0]=1;
    for(int i=1; i<N; ++i)
        f[i]=f[i-1]*i%M;
    a[N-1]=mu(f[N-1], M-2);
    for(int i=N-2; i>=0; --i)
        a[i]=a[i+1]*(i+1)%M;
}
inline ll C(int n, int k){
    if(k<0 || k>n) return 0;
    return f[n]*a[k]%M*a[n-k]%M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m; cin>>t; tienxuly();
    while(t--){ cin>>n>>m; ll res=0;
        for(int k=0; k<=m; ++k){
            ll dau=(k&1)? M-1:1;
            ll t=C(m,k)*f[2*n-k]%M*mu(2,k)%M;
            res=(res+dau*t%M)%M;
        }cout<<res<<'\n';
    }
}
