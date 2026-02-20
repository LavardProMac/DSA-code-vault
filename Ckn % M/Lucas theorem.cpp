// Sol 2: O(t*log M)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;

const int N=1e6; int M;
ll f[N+1], a[N+1];

inline ll Pow(ll a, int b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%M;
        a=a*a%M; b>>=1;
    }
    return res;
}

void tienxuly(const int& N){
    f[0]=1;
    fo(i,1,N) f[i]=f[i-1]*i%M;

    a[N]=Pow(f[N], M-2);
    fd(i,N,1) a[i-1]=a[i]*i%M;
}

inline ll C(int n, int k){
    if(k<0 || k>n) return 0;
    return f[n]*a[k]%M*a[n-k]%M;
}

ll Lucas(int n, int k){
    if(!k) return 1;
    int nM=n%M, kM=k%M;
    if(kM>nM) return 0;
    return Lucas(n/M, k/M)*C(nM, kM)%M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t, n, k; cin>>t>>M;
    tienxuly(min(N, M-1));

    while(t--) cin>>n>>k, cout<<(M>N?
        C(n, k):Lucas(n, k))<<'\n';
}
