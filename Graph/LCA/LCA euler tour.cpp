// Source: cses.fi/problemset/task/1135

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j, e=n; i<=e; ++i)
using namespace std;
const int N=2e5+5;

vector<int> g[N];
int d[N], a[N*2], p[N];
int lg[N*2], st[18][N*2], tin;

void dfs(int u, int pr){
    a[++tin]=u; p[u]=tin;
    for(int v:g[u]) if(v!=pr)
        d[v]=d[u]+1, dfs(v, u), a[++tin]=u;
}

void build(){
    st[0][1]=a[1];
    fo(i,2,tin) lg[i]=lg[i>>1]+1, st[0][i]=a[i];
    
    fo(j,1,lg[tin]) fo(i,1,tin-(1<<j)+1)
        if(d[st[j-1][i]]<d[st[j-1][i+(1<<j-1)]])
            st[j][i]=st[j-1][i];
        else st[j][i]=st[j-1][i+(1<<j-1)];
}

int lca(int u, int v){
    int l=p[u], r=p[v];
    if(l>r) swap(l, r);
    
    int i=lg[r-l+1];
    int x=st[i][l], y=st[i][r-(1<<i)+1];
    return d[x]<d[y]? x:y;
}

inline int dist(int u, int v){
    return d[u]+d[v]-2*d[lca(u, v)];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, u, v; cin>>n>>q;
    
    fo(i,2,n) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);
        
    dfs(1, 0); build();
    while(q--) cin>>u>>v,
        cout<<dist(u, v)<<'\n';
}
