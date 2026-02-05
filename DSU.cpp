#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+1;
int p[N], s[N];

inline void dsu(const int& n){
    fo(i,1,n) p[i]=i, s[i]=1;
}

inline int find(const int& x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

inline bool unite(int a, int b){
    a=find(a), b=find(b);
    if(a==b) return false;
    if(s[a]<s[b]) swap(a, b);
    p[b]=a, s[a]+=s[b];
    return true;
}

inline int get(const int& x){
    return s[f(x)];
}
