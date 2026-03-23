// Sub 2: n <= 1e5
// Mo's algorithm + BIT

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+1, BL=320;
int m, bit[N];

struct Q{
    int l, r, id;
    
    bool operator <(const Q& x) const{
        if(l/BL!=x.l/BL) return l<x.l;
        return r<x.r;
    }
} qr[N];

void upd(int i, int v){
    for(; i<=m; i+=i&-i) bit[i]+=v;
}

int get(int i, int s=0){
    for(; i; i-=i&-i) s+=bit[i];
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    
    int a[n+1], b[n+1], res[n+1];
    fo(i,1,n) cin>>a[i], b[i]=a[i];

    sort(b+1, b+n+1);
    m=unique(b+1, b+n+1)-b-1;

    fo(i,1,n)
        a[i]=lower_bound(b+1, b+m+1, a[i])-b;
    
    fo(i,1,q) qr[i].id=i,
        cin>>qr[i].l>>qr[i].r;

    sort(qr+1, qr+q+1);
    int L=1, R=0; ll s=0;

    fo(i,1,q){
        int l=qr[i].l, r=qr[i].r;

        while(R<r)
            s+=get(m)-get(a[++R]),
            upd(a[R], 1);
        
        while(R>r)
            upd(a[R], -1),
            s-=get(m)-get(a[R--]);
        
        while(L<l)
            upd(a[L], -1),
            s-=get(a[L++]-1);

        while(L>l)
            s+=get(a[--L]-1),
            upd(a[L], 1);

        res[qr[i].id]=s;
    }
    fo(i,1,q) cout<<res[i]<<'\n';
}
