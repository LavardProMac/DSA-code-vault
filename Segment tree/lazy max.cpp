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

void push(int id){
    if(!lz[id]) return;
    const int k=id<<1, v=lz[id];

    st[k]+=v; st[k|1]+=v;
    lz[k]+=v; lz[k|1]+=v;
    lz[id]=0;
}

void upd(int id,int l,int r,int u,int v,int k){
    if(r<u || l>v) return;
    if(u<=l && r<=v){
        st[id]+=k; lz[id]+=k; return;
    }
    push(id);
    const int m=l+r>>1, t=id<<1;
    
    upd(t, l, m, u, v, k);
    upd(t|1, m+1, r, u, v, k);
    st[id]=max(st[t], st[t|1]);
}

ll get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return -9e18;
    if(u<=l && r<=v) return st[id];
    
    push(id); int m=l+r>>1;
    return max(get(id<<1,l,m,u,v),
               get(id<<1|1,m+1,r,u,v));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, t, l, r, k; cin>>n;
    
    fo(i,1,n) cin>>a[i];
    build(1, 1, n); cin>>q;

    while(q--){
        cin>>t>>l>>r;
        if(t==1) cin>>k, upd(1,1,n,l,r,k);
        else cout<<get(1,1,n,l,r)<<'\n';
    }
}
