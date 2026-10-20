#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int p[200005], sz[200005];

int find(int u){
    return p[u]==u? u:p[u]=find(p[u]);
}

inline void unite(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u, v);
    p[v]=u; sz[u]+=sz[v];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);    
    int n, m, u, v, cnt=0; cin>>n>>m;
    fo(i,1,n) p[i]=i, sz[i]=1;
    
    fo(i,1,m) cin>>u>>v, unite(u, v);
    fo(i,1,n) if(i==find(i)) ++cnt;
    cout<<cnt;
}
