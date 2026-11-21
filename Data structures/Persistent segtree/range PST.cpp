// https://oj.cppro.vn/problems/caytao3

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5;
struct node{int l, r, cnt;} st[N*20+5];
int a[N+5], ver[N+5], num;

void upd(int &id, int old, int l, int r, int p){
    st[id=++num]=st[old];
    if(l==r) {++st[id].cnt; return;}
    int m=l+r>>1;
    if(p<=m) upd(st[id].l,st[id].l,l,m,p);
    else upd(st[id].r,st[id].r,m+1,r,p);
    st[id].cnt=st[st[id].l].cnt+st[st[id].r].cnt;
}

int get(int id1, int id2, int l, int r, int u, int v){
    if(l>v || r<u) return 0;
    if(u<=l && r<=v) return st[id1].cnt-st[id2].cnt;
    int m=l+r>>1;
    return get(st[id1].l,st[id2].l,l,m,u,v)+
           get(st[id1].r,st[id2].r,m+1,r,u,v);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    fo(i,1,n) cin>>a[i],
        upd(ver[i],ver[i-1],1,N,a[i]);

    while(q--){
        int l, r, x, c; cin>>l>>r>>x>>c;
        int L=x, R=n, id=-1;
        while(L<=R){
            int m=L+R>>1;
            if(get(ver[m],ver[x-1],1,N,l,r)>=c)
                id=m, R=m-1;
            else L=m+1;
        }
        cout<<id<<' ';
    }
}
