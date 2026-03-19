// Name: Range updates and sums
// Source: lqdoj.edu.vn/problem/sumq

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1;
int n, m; ll st[4*N], lz[4*N];

void build(int id,int l,int r){
    if(!lz[id]) return;
    int m=l+r>>1;

    st[id<<1]+=lz[id]*(m-l+1);
    st[id<<1|1]+=lz[id]*(r-m);

    lz[id<<1]+=lz[id];
    lz[id<<1|1]+=lz[id];
    
    lz[id]=0;
}

void upd(int id,int l,int r,int u,int v,ll k){
    if(r<u || l>v) return;

    if(u<=l && r<=v){
        st[id]+=k*(r-l+1);
        lz[id]+=k; return;
    }
    build(id,l,r); int m=l+r>>1;

    upd(id<<1, l, m, u, v, k);
    upd(id<<1|1, m+1, r, u, v, k);

    st[id]=st[id<<1]+st[id<<1|1];
}

ll get(int id,int l,int r,int u,int v){
    if(r<u || l>v) return 0;
    if(u<=l && r<=v) return st[id];
    
    build(id,l,r); int m=l+r>>1;
    
    return get(id<<1,l,m,u,v)
         + get(id<<1|1,m+1,r,u,v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, l, r; ll k; cin>>n>>m;

    while(m--){
        cin>>t>>l>>r;
        
        if(!t) cin>>k, upd(1,1,n,l,r,k);
        else cout<<get(1,1,n,l,r)<<'\n';
    }
}
