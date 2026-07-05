// Source: cses.fi/problemset/task/1673

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2505;
struct E{int u, v, w;} e[5005];

int n, m; ll d[N];
bool v1[N], v2[N];
vector<int> g[N], rg[N];

void input(){
    int u, v, w;
    fo(i,1,m)
        cin>>u>>v>>w,
        e[i]={u, v, -w},
        g[u].push_back(v),
        rg[v].push_back(u);
}

void dfs1(int u){
    v1[u]=1;
    for(int v:g[u])
        if(!v1[v]) dfs1(v);
}

void dfs2(int u){
    v2[u]=1;
    for(int v:rg[u])
        if(!v2[v]) dfs2(v);
}

void bellman_ford(){
    memset(d, 0x3f, sizeof d);
    d[1]=0;

    fo(i,1,n-1) fo(j,1,m){
        auto [u,v,w]=e[j];
        d[v]=min(d[v], d[u]+w);
    }
}

bool cycle(){
    fo(i,1,m){
        auto [u,v,w]=e[i];
        if(d[u]<4e18 && d[v]>d[u]+w
        && v1[u] && v2[v]) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    input(); dfs1(1); dfs2(n);
    
    bellman_ford();
    cout<<-(cycle()? 1:d[n]);
}
