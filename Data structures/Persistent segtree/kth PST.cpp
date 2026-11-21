// https://fptoj.com/problem/wt-kth-smallest

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5;

struct node{int l, r, cnt;} st[N*20];
int a[N], b[N], root[N], num;

int upd(int id, int l, int r, int p){
    int cur=++num;
    st[cur]=st[id]; ++st[cur].cnt;
    if(l==r) return cur;
    
    int m=l+r>>1;
    if(p<=m) st[cur].l=upd(st[id].l, l, m, p);
    else st[cur].r=upd(st[id].r, m+1, r, p);
    return cur;
}

int get(int u, int v, int l, int r, int k){
    if(l==r) return l;
    int m=l+r>>1;
    int s=st[st[v].l].cnt-st[st[u].l].cnt;
    if(k<=s) return get(st[u].l, st[v].l, l, m, k);
    return get(st[u].r, st[v].r, m+1, r, k-s);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    fo(i,1,n) cin>>a[i], b[i]=a[i];
    sort(b+1, b+n+1);
    int m=unique(b+1, b+n+1)-b-1;

    fo(i,1,n){
        int x=lower_bound(b+1, b+m+1, a[i])-b;
        root[i]=upd(root[i-1], 1, m, x);
    }
    while(q--){
        int l, r, k; cin>>l>>r>>k;
        cout<<b[get(root[l-1], root[r], 1, m, k)]<<'\n';
    }
}
