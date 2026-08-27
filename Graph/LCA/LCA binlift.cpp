// Source: cses.fi/problemset/task/1135

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5, LOG=17;

int d[N], up[LOG+1][N];
vector<int> g[N];

void dfs(int u, int p){
    up[0][u]=p;
    fo(j,1,LOG) up[j][u]=
        up[j-1][up[j-1][u]];

    for(int v:g[u]) if(v!=p)
        d[v]=d[u]+1, dfs(v, u);
}

int lca(int u, int v){
    if(d[u]<d[v]) swap(u, v);
    
    for(int j=LOG; j>=0; --j)
        if(d[u]-(1<<j)>=d[v])
            u=up[j][u];
    if(u==v) return u;

    for(int j=LOG; j>=0; --j)
        if(up[j][u]!=up[j][v])
            u=up[j][u], v=up[j][v];
    return up[0][u];
}

inline int dist(int u, int v){
    return d[u]+d[v]-2*d[lca(u, v)];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, u, v; cin>>n>>q;

    fo(i,2,n) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);
    
    dfs(1, 0);
    while(q--) cin>>u>>v,
        cout<<dist(u, v)<<'\n';
}
