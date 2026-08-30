// Source: cses.fi/problemset/task/1651

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
int a[N]; ll st[N*4], lz[N*4];

void build(int id, int l, int r){
    if(l==r) {st[id]=a[l]; return;}
    int m=l+r>>1, k=id<<1;

    build(k, l, m); build(k|1, m+1, r);
    st[id]=st[k]+st[k|1];
}

inline void push(int id, int l, int r){
    if(!lz[id]) return;
    int m=l+r>>1, k=id<<1; ll v=lz[id];

    st[k]+=v*(m-l+1); st[k|1]+=v*(r-m);
    lz[k]+=v; lz[k|1]+=v; lz[id]=0;
}

void upd(int id, int l, int r, int u, int v, int w){
    if(r<u || l>v) return;
    if(u<=l && r<=v){
        st[id]+=w*(l-r+1); lz[id]+=w;
        return;
    }
    int m=l+r>>1, k=id<<1; push(id, l, r);
    upd(k, l, m, u, v, w);
    upd(k|1, m+1, r, u, v, w);
    st[id]=st[k]+st[k|1];
}

ll get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return 0;
    if(u<=l && r<=v) return st[id];

    int m=l+r>>1, k=id<<1; push(id, l, r);
    return get(k, l, m, u, v)+
           get(k|1, m+1, r, u, v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    fo(i,1,n) cin>>a[i];
    build(1, 1, n);

    while(q--){
        int t, l, r, v; cin>>t>>l;
        if(t==1) cin>>r>>v,
            upd(1, 1, n, l, r, v);
        else cout<<
            get(1, 1, n, l, l)<<'\n';
    }
}
