// Name:

#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const ll N=2e5+5, INF=4e18;

pll p[N];
ll pr[N], mx[N], dl[N], l[N];

inline bool cmp(const pll& x, const pll& y){
    return x.s<y.s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("IOIDSA.INP", "r", stdin);
    freopen("IOIDSA.OUT", "w", stdout);
    int n, m, q; cin>>n>>m>>q;

    fo(i,1,n) cin>>p[i].f;
    fo(i,1,n) cin>>p[i].s;
    
    sort(p+1, p+n+1, cmp);
    fo(i,1,m) cin>>l[i], l[i]+=l[i-1];

    fo(i,1,n) dl[i]=p[i].s,
        pr[i]=pr[i-1]+p[i].f,

    mx[n]=pr[n]-dl[n];
    for(int i=n-1; i; --i)
        mx[i]=max(mx[i+1], pr[i]-dl[i]);

    while(q--){
        ll t; cin>>t;
        int id=upper_bound(dl+1, dl+n+1, t)-dl-1;

        ll nd=pr[id];
        if(id<n) nd=max(nd, t+mx[id+1]);

        int ans=upper_bound(l+1, l+m+1, t-nd)-l-1;
        cout<<ans<<' ';
    }
}
