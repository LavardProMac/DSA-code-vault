// https://oj.cppro.vn/problems/vosplay

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int p[N], sz[N], h[N], nxt[N];
int u[N], v[N], lo[N], hi[N];
vector<int> b[N];

int find(int u){
    return p[u]==u? u:p[u]=find(p[u]);
}
inline void unite(int u, int v){
    u=find(u), v=find(v);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u, v);
    p[v]=u; sz[u]+=sz[v];
}
inline bool kt(int g){
    int r=find(h[g]);
    for(int u=nxt[h[g]]; u; u=nxt[u])
        if(find(u)!=r) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q, x; cin>>n>>m>>q;
    fo(i,1,n) cin>>x, nxt[i]=h[x], h[x]=i;
    fo(i,1,q) cin>>u[i]>>v[i];

    fo(i,1,m)
        if(!nxt[h[i]]) lo[i]=hi[i]=0;
        else lo[i]=1, hi[i]=q+1;

    while(true){
        bool ok=0;
        fo(i,1,q+1) b[i].clear();

        fo(i,1,m) if(lo[i]<hi[i]) ok=1,
            b[lo[i]+hi[i]>>1].push_back(i);
        if(!ok) break;
        fo(i,1,n) p[i]=i, sz[i]=1;

        fo(i,1,q){
            unite(u[i], v[i]);
            for(int g:b[i])
                if(kt(g)) hi[g]=i;
                else lo[g]=i+1;
        }
    }
    fo(i,1,m)
        if(!nxt[h[i]]) cout<<"0\n";
        else if(lo[i]==q+1) cout<<"-1\n";
        else cout<<lo[i]<<'\n';
}
