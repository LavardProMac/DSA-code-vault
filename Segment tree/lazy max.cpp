// Name: ITLAZY
// Source: oj.vnoi.info/problem/segtree_itlazy

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1;
int a[N]; ll st[N<<2], lz[N<<2];

void build(int id, int l, int r){
    if(l==r) {st[id]=a[l]; return;}
    const int m=l+r>>1, k=id<<1;

    build(k,l,m); build(k|1,m+1,r);
    st[id]=max(st[k], st[k|1]);
}

inline void push(int id){
    if(!lz[id]) return;
    
    int k=id<<1; ll v=lz[id]; lz[id]=0;
    fo(i,k,k+1) st[i]+=v, lz[i]+=v;
}

void upd(int id, int l, int r, int u, int v, int k){
    if(r<u || l>v) return;
    
    if(u<=l && r<=v){
        st[id]+=k; lz[id]+=k; return;
    }
    const int m=l+r>>1, t=id<<1; push(id);
    upd(t,l,m,u,v,k); upd(t|1,m+1,r,u,v,k);
    
    st[id]=max(st[t], st[t|1]);
}

ll get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return -9e18;
    if(u<=l && r<=v) return st[id];
    
    int m=l+r>>1, k=id<<1; push(id);
    return max(get(k,l,m,u,v), get(k|1,m+1,r,u,v));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n;
    
    fo(i,1,n) cin>>a[i];
    build(1, 1, n); cin>>q;

    while(q--){
        int t, l, r, k; cin>>t>>l>>r;
        if(t==1) cin>>k, upd(1,1,n,l,r,k);
        else cout<<get(1,1,n,l,r)<<'\n';
    }
}
