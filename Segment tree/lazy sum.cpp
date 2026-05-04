// Name: Range updates and sums
// Source: lqdoj.edu.vn/problem/sumq

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1;
int a[N]; ll st[N<<2], lz[N<<2];

void build(int id, int l, int r){
    if(l==r) {st[id]=a[l]; return;}
    int m=l+r>>1, k=id<<1;

    build(k,l,m); build(k|1,m+1,r);
    st[id]=st[k]+st[k|1];
}

void push(int id, int l, int r){
    if(!lz[id]) return;
    int m=l+r>>1, k=id<<1;

    st[k]+=lz[id]*(m-l+1); st[k|1]+=lz[id]*(r-m);
    lz[k]+=lz[id]; lz[k|1]+=lz[id]; lz[id]=0;
}

void upd(int id, int l, int r, int u, int v, ll k){
    if(r<u || l>v) return;

    if(u<=l && r<=v){
        st[id]+=k*(r-l+1); lz[id]+=k; return;
    }
    int m=l+r>>1, t=id<<1; push(id, l, r);
    upd(t,l,m,u,v,k); upd(t|1,m+1,r,u,v,k);

    st[id]=st[t]+st[t|1];
}

ll get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return 0;
    if(u<=l && r<=v) return st[id];
    
    int m=l+r>>1, k=id<<1; push(id, l, r);
    return get(k,l,m,u,v)+get(k|1,m+1,r,u,v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;

    while(q--){
        int t, l, r; ll k; cin>>t>>l>>r;
        if(!t) cin>>k, upd(1,1,n,l,r,k);
        else cout<<get(1,1,n,l,r)<<'\n';
    }
}
