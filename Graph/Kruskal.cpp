// Source: oj.clue.edu.vn/problem/tq_tst_23_c

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct edge{int u, v, w;} a[100001];
int p[10001];

bool cmp(const edge& a, const edge& b){
    return a.w>b.w;
}

inline int find(int x){
    return p[x]==x? x:p[x]=find(p[x]);
}

inline void unite(int u, int v){
    u=find(u); v=find(v);
    if(u!=v) p[v]=u;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y; cin>>n>>m>>x>>y;

    fo(i,1,m) cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a+1, a+m+1, cmp);
    fo(i,1,n) p[i]=i;

    fo(i,1,m){
        unite(a[i].u, a[i].v);
        if(find(x)==find(y))
            return cout<<a[i].w, 0;
    }
    cout<<0;
}
