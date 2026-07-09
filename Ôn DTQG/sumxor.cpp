#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l; i<=r; i++)
using namespace std;

const int N=1e6+5;
int n, a[N], b[N], p[N], bit[N], ans[N];

struct Q{int r, l, id;} qr[N];
int lst[N];

void upd(int i, int v){
    if(!i) return;
    for(; i<=n; i+=i&-i) bit[i]^=v;
}

int get(int i, int s=0){
    for(; i; i-=i&-i) s^=bit[i];
    return s;
}

bool cmp(const Q& a, const Q& b){
    return a.r<b.r;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("sumxor.inp", "r", stdin);
    freopen("sumxor.out", "w", stdout);
    int t; cin>>t>>n;
    
    fo(i,1,n) cin>>a[i], p[i]=p[i-1]^(b[i]=a[i]);
    int q, cur=1; cin>>q;
    
    sort(a+1, a+n+1);
    int m=unique(a+1, a+n+1)-a-1;

    fo(i,1,q) cin>>qr[i].l>>qr[i].r, qr[i].id=i;
    sort(qr+1, qr+q+1, cmp);
    
    fo(i,1,q){
        while(cur<=qr[i].r){
            int id=lower_bound(a+1, a+m+1, b[cur])-a;
            if(lst[id]) upd(lst[id], b[cur]);
            upd(cur, b[cur]); lst[id]=cur++;
        }
        ans[qr[i].id]=p[qr[i].r]^p[qr[i].l-1]
                ^get(qr[i].r)^get(qr[i].l-1);
    }
    fo(i,1,q) cout<<ans[i]<<' ';
}
