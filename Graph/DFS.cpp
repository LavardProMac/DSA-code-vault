// DFS O(N+M)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

unordered_map<int, vector<int>> g;
unordered_map<int, int> p; // parent
unordered_map<int, bool> d;

void dfs(int u){
    cout<<u<<' '; d[u]=1;
    
    for(int v:g[u]) if(!d[v])
        p[v]=u, dfs(v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    
    fo(i,1,m) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);

    fo(i,1,n) if(!d[i]) dfs(i);
}
