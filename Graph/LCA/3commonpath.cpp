#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5, LOG=17;

int d[N], up[N][LOG+1], leaf[N], sum[N];
vector<int> g[N];

void dfs(int u, int p){
    up[u][0]=p;
    fo(i,1,LOG) up[u][i]=up[up[u][i-1]][i-1];

    leaf[u]=u!=1 && g[u].size()==1;
    sum[u]=sum[p]+leaf[u];

    for(int v:g[u]) if(v!=p)
        d[v]=d[u]+1, dfs(v, u);
}

inline int lca(int u, int v){
    if(d[u]<d[v]) swap(u, v);
    for(int i=LOG; i>=0; --i)
        if(d[u]-(1<<i)>=d[v]) u=up[u][i];
    if(u==v) return u;

    for(int i=LOG; i>=0; --i)
        if(up[u][i]!=up[v][i])
            u=up[u][i], v=up[v][i];
    return up[u][0];
}

inline int lc3(int a, int b, int c){
    int x=lca(a, b), y=lca(a, c), z=lca(b, c);
    if(d[x]>=d[y] && d[x]>=d[z]) return x;
    if(d[y]>=d[z]) return y;
    return z;
}

inline int qry(int a, int b, int c){
    int p=lc3(a, b, c), l=lca(p, c);
    return sum[p]+sum[c]-2*sum[l]+leaf[l];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, u, v, a, b, c; cin>>n;

    fo(i,2,n) cin>>u>>v,
        g[u].emplace_back(v),
        g[v].emplace_back(u);
    dfs(1, 0); int q; cin>>q;
    
    while(q--) cin>>a>>b>>c,
        cout<<max({qry(a, b, c),
        qry(a, c, b), qry(b, c, a)})<<'\n';
}
