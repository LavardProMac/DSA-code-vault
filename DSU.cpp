#include<bits/stdc++.h>
using namespace std;
int p[1000005], s[1000005];

inline void dsu(int n){
    for(int i=0; i<n; ++i)
        p[i]=i, s[i]=1;
}
inline int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
inline bool unite(int a, int b){
    a=find(a), b=find(b);
    if(a==b) return 0;
    if(s[a]<s[b]) swap(a, b);
    p[b]=a, s[a]+=s[b];
    return 1;
}
inline int get(int x){
    return s[f(x)];
}
