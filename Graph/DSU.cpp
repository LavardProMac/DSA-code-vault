#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+1;
int p[N], sz[N];

void init(const int& n){
    fo(i,1,n) p[i]=i, sz[i]=1;
}

inline int find(const int& x){
    return p[x]==x? x:p[x]=find(p[x]);
}

inline bool unite(int a, int b){
    a=find(a), b=find(b);
    
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a, b);
    
    p[b]=a, sz[a]+=sz[b];
    return true;
}

inline int getsz(const int& x){
    return sz[find(x)];
}
