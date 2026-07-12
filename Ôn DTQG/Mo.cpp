// Source: csp.vnoi.info/problem/wquery

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int B=316;
int d[1000006]; ll cur;

struct qry{
    int l, r, id;
    bool operator<(const qry &o) const{
        if(l/B!=o.l/B) return l<o.l;
        return l/B&1? r>o.r:r<o.r;
    }
};

inline void add(int x){
    cur+=(2ll*d[x]+++1)*x;
}

inline void del(int x){
    cur-=(2ll*--d[x]+1)*x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, Q; cin>>n>>Q;
    int a[n+1], l=1, r=0;
    
    qry q[Q+1]; ll ans[Q+1];
    fo(i,1,n) cin>>a[i];

    fo(i,1,Q) cin>>q[i].l>>q[i].r,
        ++q[i].l, ++q[i].r, q[i].id=i;
    sort(q+1, q+Q+1);

    fo(i,1,Q){
        int L=q[i].l, R=q[i].r;
        while(l>L) add(a[--l]);
        while(r<R) add(a[++r]);
        while(l<L) del(a[l++]);
        while(r>R) del(a[r--]);
        ans[q[i].id]=cur;
    }
    fo(i,1,Q) cout<<ans[i]<<'\n';
}
