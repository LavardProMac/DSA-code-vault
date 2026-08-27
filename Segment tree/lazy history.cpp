// Source: pbck55.contest.codeforces.com/group/lB3Zfkud0s/contest/712837/problem/E

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5;

struct node{
    ll ma, mb, la, lb;
} st[N<<2]; ll a[N];

void build(int id, int l, int r){
    if(l==r){
        st[id]={a[l], a[l], 0, 0};
        return;
    }
    int mid=l+r>>1, k=id<<1;
    build(k, l, mid);
    build(k|1, mid+1, r);
    
    st[id].ma=max(st[k].ma, st[k|1].ma);
    st[id].mb=max(st[k].mb, st[k|1].mb);
    st[id].la=st[id].lb=0;
}

inline void apply(int id, ll va, ll vb){
    st[id].mb=max(st[id].mb, st[id].ma+vb);
    st[id].ma+=va;
    st[id].lb=max(st[id].lb, st[id].la+vb);
    st[id].la+=va;
}

inline void push(int id){
    if(st[id].la || st[id].lb)
        apply(id<<1, st[id].la, st[id].lb),
        apply(id<<1|1, st[id].la, st[id].lb),
        st[id].la=st[id].lb=0;
}

void upd(int id, int l, int r, int ql, int qr, ll v){
    if(ql<=l && r<=qr){
        apply(id, v, v); return;
    }
    push(id); int mid=l+r>>1, k=id<<1;
    if(ql<=mid) upd(k, l, mid, ql, qr, v);
    if(qr>mid) upd(k|1, mid+1, r, ql, qr, v);
    
    st[id].ma=max(st[k].ma, st[k|1].ma);
    st[id].mb=max(st[k].mb, st[k|1].mb);
}

ll get(int id, int l, int r, int ql, int qr, int t){
    if(ql<=l && r<=qr)
        return t==2? st[id].ma:st[id].mb;
    
    push(id); int mid=l+r>>1, k=id<<1;
    if(qr<=mid) return get(k, l, mid, ql, qr, t);
    if(ql>mid) return get(k|1, mid+1, r, ql, qr, t);
    
    return max(get(k, l, mid, ql, qr, t),
               get(k|1, mid+1, r, ql, qr, t));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    fo(i,1,n) cin>>a[i];
    build(1, 1, n);
    
    while(q--){
        int t, l, r, v; cin>>t>>l>>r;
        if(t==1) cin>>v, upd(1, 1, n, l, r, v);
        else cout<<get(1, 1, n, l, r, t)<<'\n';
    }
}
