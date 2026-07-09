// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/I

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define fo(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;
const int N=1e6+5;

int a[N], rs[N];
pii st[N<<2]; ll lz[N<<2];

inline pii Min(pii x, pii y){
    if(x.s==0) return y;
    if(y.s==0) return x;
    return min(x, y);
}

void build(int id, int l, int r){
    if(l==r){
        st[id]={a[l], l}; return;
    }
    const int m=l+r>>1, k=id<<1;
    build(k, l, m); build(k|1, m+1, r);
    st[id]=Min(st[k], st[k|1]);
}

void down(int id, int l, int r){
    if(l==r) return;
    const int k=id<<1;
    
    if(st[k].s)
        st[k].f+=lz[id], lz[k]+=lz[id];
    if(st[k|1].s)
        st[k|1].f+=lz[id], lz[k|1]+=lz[id];
    lz[id]=0;
}

void del(int id, int l, int r, int i, int x){
    if(l>i || r<i) return;
    if(l==r) {st[id]={x, 0}; return;}
    
    down(id, l, r);
    const int m=l+r>>1, k=id<<1;
    
    del(k, l, m, i, x);
    del(k|1, m+1, r, i, x);
    st[id]=Min(st[k], st[k|1]);
}

void upd(int id, int l, int r, int u, int v, int x){
    if(!st[id].s) return;
    if(l>v || r<u) return;
    
    if(l>=u && r<=v){
        st[id].f+=x, lz[id]+=x;
        return;
    }
    down(id, l, r);
    const int m=l+r>>1, k=id<<1;
    
    upd(k, l, m, u, v, x);
    upd(k|1, m+1, r, u, v, x);
    st[id]=Min(st[k], st[k|1]);
}

pii get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return {0, 0};
    if(l>=u && r<=v) return st[id];
    
    down(id, l, r);
    const int m=l+r>>1, k=id<<1;
    
    return Min(get(k, l, m, u, v),
               get(k|1, m+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    
    fo(i,1,n) cin>>a[i], rs[i]=q+1;
    build(1, 1, n);

    fo(o,1,q){
        int x, y, w; cin>>x>>y>>w;
        upd(1, 1, n, x, y, -w);

        while(true){
            auto p=get(1, 1, n, x, y);
            if(!p.s || p.f>0) break;
            del(1, 1, n, p.s, 0);
            rs[p.s]=o;
        }
    }
    fo(i,1,n) for(int j=1; j*i<=n; ++j)
        rs[i]=max(rs[i], rs[i*j]);

    fo(i,1,n) if(rs[i]==q+1) rs[i]=-1;
    fo(i,1,n) cout<<rs[i]<<' ';
}
