// Source: cses.fi/problemset/task/1135

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5, LOG=17;

int d[N], up[N][LOG+1];
vector<int> g[N];

void dfs(int u, int p){
    up[u][0]=p;
    fo(i,1,LOG) up[u][i]=
        up[up[u][i-1]][i-1];

    for(int v:g[u]) if(v!=p)
        d[v]=d[u]+1, dfs(v, u);
}

int lca(int u, int v){
    if(d[u]<d[v]) swap(u, v);

    for(int i=LOG; i>=0; --i)
        if(d[u]-(1<<i)>=d[v])
            u=up[u][i];
    if(u==v) return u;

    for(int i=LOG; i>=0; --i)
        if(up[u][i]!=up[v][i])
            u=up[u][i], v=up[v][i];
    return up[u][0];
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
