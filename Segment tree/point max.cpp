// Source: oj.vnoi.info/problem/segtree_itez1

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
int a[N]; ll st[N<<2];

void build(int id, int l, int r){
    if(l==r) {st[id]=a[l]; return;}
    int m=l+r>>1, k=id<<1;

    build(k,l,m); build(k|1,m+1,r);
    st[id]=max(st[k], st[k|1]);
}

void upd(int id,int l,int r,int p,int v){
    if(l==r) {st[id]=v; return;}
    int m=l+r>>1, k=id<<1;

    if(p<=m) upd(k, l, m, p, v);
    else upd(k|1, m+1, r, p, v);

    st[id]=max(st[k], st[k|1]);
}

ll get(int id,int l,int r,int u,int v){
    if(r<u || l>v) return -9e18;
    if(u<=l && r<=v) return st[id];
    int m=l+r>>1;

    return max(get(id<<1,l,m,u,v),
               get(id<<1|1,m+1,r,u,v));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, t, l, r; cin>>n;
    
    fo(i,1,n) cin>>a[i];
    build(1, 1, n); cin>>q;

    while(q--){
        cin>>t>>l>>r;
        if(t==1) upd(1,1,n,l,r);
        else cout<<get(1,1,n,l,r)<<'\n';
    }
}
