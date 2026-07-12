// Source: csp.vnoi.info/problem/lmh_treematch

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

vector<pair<int, int>> a[N];
int p[N]; ll g[N], f[N];

void dfs(int u, int p){
    ll mx=0;
    for(auto [v,w]:a[u]) if(v!=p)
        dfs(v, u), g[u]+=f[v],
        mx=max(mx, w+g[v]-f[v]);
    f[u]=g[u]+mx;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, u, v, w; cin>>n;
    
    fo(i,1,n-1) cin>>u>>v>>w,
        a[u].emplace_back(v, w),
        a[v].emplace_back(u, w);
    
    dfs(1, 0);
    cout<<max(g[1], f[1]);
}
