// Source: oj.vnoi.info/problem/graph_

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e4+5;

int tin[N], low[N], t, khop, cau;
vector<pair<int, int>> g[N];

void dfs(int u, int p){
    tin[u]=low[u]=++t;
    int cnt=0; bool ok=0;

    for(auto [v, id]:g[u]) if(id!=p)
        if(tin[v])
            low[u]=min(low[u], tin[v]);
        else dfs(v, id), ++cnt,
            low[u]=min(low[u], low[v]),
            cau+=low[v]>tin[u],
            ok|=low[v]>=tin[u];
    khop+=p? ok:cnt>1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;

    fo(i,1,m) cin>>u>>v,
        g[u].emplace_back(v, i),
        g[v].emplace_back(u, i);

    fo(i,1,n) if(!tin[i]) dfs(i, 0);
    cout<<khop<<' '<<cau;
}
