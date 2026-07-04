// Source: cses.fi/problemset/task/1675

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct edge{int u, v, w;} a[200005];
int p[100005];

bool cmp(const edge& a, const edge& b){
    return a.w<b.w;
}

inline int find(int x){
    return p[x]==x? x:p[x]=find(p[x]);
}

inline bool unite(int u, int v){
    u=find(u); v=find(v);
    return u==v? 0:p[v]=u;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; ll ans=0; cin>>n>>m;
    fo(i,1,m) cin>>a[i].u>>a[i].v>>a[i].w;
    
    sort(a+1, a+m+1, cmp);
    fo(i,1,n) p[i]=i;

    fo(i,1,m) if(unite(a[i].u, a[i].v))
        ans+=a[i].w, --n;
    
    if(n>1) cout<<"IMPOSSIBLE";
    else cout<<ans;
}
