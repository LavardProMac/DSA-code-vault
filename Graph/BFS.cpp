// Source: cses.fi/problemset/task/1667

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
vector<int> g[N]; int d[N], t[N];

void bfs(){
    memset(d, -1, sizeof d);
    queue<int> q; q.push(1); d[1]=0;

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]) if(d[v]==-1)
            d[v]=d[u]+1, t[v]=u, q.push(v);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;

    fo(i,1,m) cin>>u>>v,
        g[u].pb(v), g[v].pb(u);

    bfs(); vector<int> a;
    if(d[n]==-1)
        return cout<<"IMPOSSIBLE", 0;

    for(int u=n; u; u=t[u]) a.pb(u);
    reverse(a.begin(), a.end());
    
    cout<<a.size()<<'\n';
    for(int i:a) cout<<i<<' ';
}
