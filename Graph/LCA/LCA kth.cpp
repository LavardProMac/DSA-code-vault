// Source: vjudge.net/contest/844907#problem/B

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e4+5, LOG=13;

int d[N], d2[N], up[N][LOG+1];
vector<pii> g[N];

void dfs(int u, int p){
    up[u][0]=p;
    fo(i,1,LOG) up[u][i]=
        up[up[u][i-1]][i-1];

    for(auto [v, w]:g[u]) if(v!=p)
        d2[v]=d2[u]+1,
        d[v]=d[u]+w, dfs(v, u);
}

inline int lca(int u, int v){
    if(d2[u]<d2[v]) swap(u, v);

    for(int i=LOG; i>=0; --i)
        if(d2[u]-(1<<i)>=d2[v])
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

inline int anc(int u, int k){
    fo(i,0,LOG) if(k>>i&1) u=up[u][i];
    return u;
}

inline int kth(int u, int v, int k){
    int l=lca(u, v);
    int du=d2[u]-d2[l], dv=d2[v]-d2[l];

    if(k<=du+1) return anc(u, k-1);
    else return anc(v, du+dv-k+1);
}

void solve(){
    int n, u, v, w; cin>>n;
    fo(i,1,n) g[i].clear();

    fo(i,2,n) cin>>u>>v>>w,
        g[u].emplace_back(v, w),
        g[v].emplace_back(u, w);

    memset(d, 0, sizeof d);
    memset(d2, 0, sizeof d2);
    dfs(1, 0); string s; int k;

    while(cin>>s)
        if(s=="DIST") cin>>u>>v,
            cout<<dist(u, v)<<'\n';
        else if(s=="KTH") cin>>u>>v>>k,
            cout<<kth(u, v, k)<<'\n';
        else break;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}
