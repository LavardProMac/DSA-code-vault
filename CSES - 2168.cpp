// Name: Nested Ranges Check
// Source: cses.fi/problemset/task/2168

#include<bits/stdc++.h>
#define ll long long
#define esc(s) return cout<<(s), 0
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
#pragma GCC target("avx2,bmi2")
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

int l[200005], r[200005];

inline bool cmp(int a, int b){
    if(l[a]==l[b]) return r[a]>r[b];
    return l[a]<l[b];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n; int id[n+1];
    bool kq1[n+1]={}, kq2[n+1]={};
    ll mi=1e18, mx=0;
    
    fo(i,1,n) cin>>l[i]>>r[i], id[i]=i;
    sort(id+1, id+n+1, cmp);
    
    fd(i,n,1)
        if(r[id[i]]>=mi) kq1[id[i]]=1;
        else mi=r[id[i]];
    
    fo(i,1,n)
        if(r[id[i]]<=mx) kq2[id[i]]=1;
        else mx=r[id[i]];
    
    fo(i,1,n) cout<<kq1[i]<<' ';
    cout<<'\n';
    fo(i,1,n) cout<<kq2[i]<<' ';
}
