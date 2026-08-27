// Source: vjudge.net/contest/844907#problem/D

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5, LOG=17;

int d[N], up[N][LOG+1];
vector<int> g[N];

void dfs(int u, int p){
    up[u][0]=p;
    fo(i,1,LOG) up[u][i]=
        up[up[u][i-1]][i-1];

    for(int v:g[u]) if(v!=p)
        d[v]=d[u]+1, dfs(v, u);
}

inline int lca(int u, int v){
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

inline int lca3(int a, int b, int c){
    int x=lca(a, b), y=lca(b, c), z=lca(c, a);
    if(d[x]>=d[y] && d[x]>=d[z]) return x;
    return d[y]>=d[z]? y:z;
}

inline int dist(int u, int v){
    return d[u]+d[v]-2*d[lca(u, v)];
}

inline int qry(int a, int b, int c){
    int l=lca3(a, b, c);
    return 1+max({dist(a, l),
        dist(b, l), dist(c, l)});
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, a, b, c; cin>>n>>q;

    fo(i,2,n) cin>>a,
        g[a].push_back(i),
        g[i].push_back(a);
    dfs(1, 0);

    while(q--) cin>>a>>b>>c,
        cout<<qry(a, b, c)<<'\n';
}
