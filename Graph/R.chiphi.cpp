// Source: chuyentinpbc.ucode.vn/problems/13rchiphidt-211927

#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;
int p[10001];

struct edge{
    int u, v, w;
    bool operator<(const edge& e) const{
        return w>e.w;
    }
};

inline int find(int x){
    return p[x]==x? x:p[x]=find(p[x]);
}

inline bool unite(int a, int b){
    a=find(a), b=find(b);
    return a!=b? p[b]=a:0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    edge a[m+1]; ll ans=0;
    
    fo(i,1,m)
        cin>>a[i].u>>a[i].v>>a[i].w,
        ans+=a[i].w;
        
    sort(a+1, a+m+1);
    fo(i,1,n) p[i]=i;
    
    fo(i,1,m) if(unite(a[i].u, a[i].v))
        ans-=a[i].w;
    cout<<ans;
}
