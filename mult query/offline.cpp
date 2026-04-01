#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int M=1e9+7;

ll Pow(ll a, ll b, ll res=1){
    while(b){
        if(b&1) res=res*a%M;
        a=a*a%M; b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r; cin>>n>>q;
    
    ll a[n+1], p[n+2], k; p[0]=1;
    fo(i,1,n) cin>>a[i], p[i]=1;

    fo(i,1,q) cin>>l>>r>>k,
        p[l]=p[l]*k%M,
        p[r+1]=p[r+1]*Pow(k, M-2)%M;

    fo(i,1,n) p[i]=p[i]*p[i-1]%M,
        cout<<a[i]*p[i]%M<<' ';
}
