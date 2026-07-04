// Source: cses.fi/problemset/task/1672

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int n, m, u, v; ll w, d[505][505];

void init(){
    memset(d, 0x3f, sizeof d);
    fo(i,1,n) d[i][i]=0;
}

void input(){
    fo(i,1,m) cin>>u>>v>>w,
        d[u][v]=min(d[u][v], w),
        d[v][u]=min(d[v][u], w);
}

void floyd(){
    fo(k,1,n) fo(i,1,n) fo(j,1,n)
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}

void solve(){
    cin>>u>>v;
    cout<<(d[u][v]>4e18? -1:d[u][v])<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>m>>q;
    
    init(); input(); floyd();
    while(q--) solve();
}
