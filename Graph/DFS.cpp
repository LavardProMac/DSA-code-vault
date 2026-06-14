// DFS O(N+M)

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

unordered_map<int, vector<int>> g;
unordered_map<int, int> p; // parent
unordered_map<int, bool> d;

void dfs(int u){
    d[u]=1; // cout<<u<<' ';
    
    for(int v:g[u]) if(!d[v])
        p[v]=u, dfs(v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    vector<int> a;
    
    fo(i,1,m) cin>>u>>v,
        g[u].pb(v), g[v].pb(u),
        a.pb(u), a.pb(v);
        
    sort(all(a));
    a.erase(unique(all(a)), a.end());

    for(int i:a) if(!d[i]) dfs(i);
    // for(int i:a) cout<<p[i]<<' ';
}
