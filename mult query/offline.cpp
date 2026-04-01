#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r; cin>>n>>q;
    ll a[n+1], p[n+1], d[n+2], k;
    
    fo(i,1,n) cin>>a[i]; p[0]=1;
    fo(i,1,n) p[i]=d[i]=1;

    fo(i,1,q) cin>>l>>r>>k,
        p[l]*=k, d[r+1]*=k;

    fo(i,1,n) cout<<a[i]*
        (p[i]=p[i-1]*p[i]/d[i])<<' ';
}
