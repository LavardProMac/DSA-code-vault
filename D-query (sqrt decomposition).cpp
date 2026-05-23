#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e6+5, B=200;
int n, a[N], c[N], cur;

struct tp{
    int l, r, id;
    bool operator<(const tp& o) const{
        int x=l/B, y=o.l/B;
        if(x!=y) return x<y;
        return x&1? r>o.r:r<o.r;
    }
} Q[N];

inline void add(int i){
    if(!c[a[i]]++) ++cur;
}

inline void del(int i){
    if(!--c[a[i]]) --cur;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    
    fo(i,1,n) cin>>a[i];
    int q, l=1, r=0; cin>>q;
    
    fo(i,1,q) cin>>Q[i].l>>Q[i].r, Q[i].id=i;
    sort(Q+1, Q+q+1); int ans[q+1];

    fo(i,1,q){
        int L=Q[i].l, R=Q[i].r;
        while(r<R) add(++r);
        while(r>R) del(r--);
        while(l<L) del(l++);
        while(l>L) add(--l);
        ans[Q[i].id]=cur;
    }
    fo(i,1,q) cout<<ans[i]<<'\n';
}
