// Source: csp.vnoi.info/problem/lmh_pickup

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=5005;
ll t[N], p[N], f[N], g[N];

inline ll cost(int j, int i){
    return (i-j+1)*t[i]-p[i]+p[j-1];
}

void solve(int l, int r, int pl, int pr){
    if(l>r) return;
    int m=l+r>>1, p=-1; g[m]=1e18;
    
    fo(j,pl,min(m, pr)){
        ll v=f[j-1]+cost(j, m);
        if(v<g[m]) g[m]=v, p=j;
    }
    solve(l, m-1, pl, p);
    solve(m+1, r, p, pr);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    fo(i,1,n) cin>>t[i];
    
    sort(t+1, t+n+1);
    fo(i,1,n) p[i]=p[i-1]+t[i];
    fo(i,1,n) f[i]=cost(1, i);

    fo(k,2,m) solve(1, n, 1, n),
        memcpy(f, g, n+1<<3);
    cout<<f[n];
}
