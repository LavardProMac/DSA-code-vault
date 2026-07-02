// Source: lqdoj.edu.vn/problem/longestpath

#include<bits/stdc++.h>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int d[N], f[N], ans;
vector<int> g[N];

int dfs(int u){
    if(f[u]!=-1) return f[u];
    f[u]=0;
    
    for(int v:g[u])
        f[u]=max(f[u], dfs(v)+1);
    return f[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;

    fo(i,1,m) cin>>u>>v,
        g[u].push_back(v), ++d[v];
    memset(f, -1, sizeof f);

    fo(i,1,n) if(!d[i])
        ans=max(ans, dfs(i));
    cout<<ans;
}
