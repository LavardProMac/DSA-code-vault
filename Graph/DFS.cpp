// Source: cses.fi/problemset/task/1666

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
vector<int> g[N]; bitset<N> d;

void dfs(int u){
    d[u]=1;
    for(int v:g[u]) if(!d[v]) dfs(v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    
    fo(i,1,m) cin>>u>>v,
        g[u].pb(v), g[v].pb(u);
    
    vector<int> a;
    fo(i,1,n) if(!d[i]) a.pb(i), dfs(i);
    
    cout<<(n=a.size()-1)<<'\n';
    fo(i,1,n)
        cout<<a[i-1]<<' '<<a[i]<<'\n';
}
