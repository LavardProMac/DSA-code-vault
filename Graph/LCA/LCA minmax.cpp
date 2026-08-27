// Source: vjudge.net/contest/844907#problem/C

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5, LOG=17;

int d[N], up[N][LOG+1];
int mi[N][LOG+1], mx[N][LOG+1];
vector<pair<int, int>> g[N];

void dfs(int u, int p){
    up[u][0]=p;
    fo(i,1,LOG) up[u][i]=up[up[u][i-1]][i-1],
        mi[u][i]=min(mi[u][i-1], mi[up[u][i-1]][i-1]),
        mx[u][i]=max(mx[u][i-1], mx[up[u][i-1]][i-1]);

    for(auto [v, w]:g[u]) if(v!=p)
        mi[v][0]=mx[v][0]=w,
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

inline pair<int, int> qry(int u, int v){
    int mn=2e9, ma=0, l=lca(u, v);
    for(int i=LOG; i>=0; --i)
        if(d[u]-(1<<i)>=d[l])
            mn=min(mn, mi[u][i]),
            ma=max(ma, mx[u][i]),
            u=up[u][i];
        
    for(int i=LOG; i>=0; --i)
        if(d[v]-(1<<i)>=d[l])
            mn=min(mn, mi[v][i]),
            ma=max(ma, mx[v][i]),
            v=up[v][i];
    return {mn, ma};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, u, v, w; cin>>n;

    fo(i,2,n) cin>>u>>v>>w,
        g[u].emplace_back(v, w),
        g[v].emplace_back(u, w);

    memset(mi, 0x3f, sizeof mi);
    dfs(1, 0); int q; cin>>q;

    while(q--){
        cin>>u>>v;
        auto [mi, mx]=qry(u, v);
        cout<<mi<<' '<<mx<<'\n';
    }
}
