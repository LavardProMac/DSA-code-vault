#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define update upd(1,1,m,x,ms[x].empty()? INF:*ms[x].begin())
using namespace std;
const int N=1e6+1, INF=2e9;

int m, a[N], st[N<<2];
multiset<int> ms[N];

void upd(int id, int l, int r, int p, int v){
    if(l==r) {st[id]=v; return;}
    int m=l+r>>1, k=id<<1;

    if(p<=m) upd(k,l,m,p,v);
    else upd(k|1,m+1,r,p,v);
    st[id]=min(st[k], st[k|1]);
}

int get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return INF;
    if(u<=l && r<=v) return st[id];

    int m=l+r>>1, k=id<<1;
    return min(get(k, l, m, u, v),
               get(k|1,m+1,r,u,v));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);

    int n, k, x; cin>>n>>k;
    memset(st, 0x3f, sizeof st);

    int a[n+1], b[n+1], dp[n+1]; dp[1]=0;
    fo(i,1,n) cin>>a[i], b[i]=a[i];

    sort(b+1, b+n+1);
    m=unique(b+1, b+n+1)-b-1;

    a[1]=x=lower_bound(b+1, b+m+1, a[1])-b;
    ms[x].insert(0); update;

    fo(i,2,n){
        if(i>k+1)
            ms[a[x=i-k-1]].erase(ms[a[x]].find(dp[x])),
            x=a[x], update;

        a[i]=x=lower_bound(b+1, b+m+1, a[i])-b;
        dp[i]=min(get(1,1,m,1,x)+1, get(1,1,m,x+1,m));
        ms[x].insert(dp[i]); update;
    }
    cout<<dp[n];
}
