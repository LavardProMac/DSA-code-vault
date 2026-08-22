// Source: hnoj.edu.vn/problem/t6lrsort

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1005;
const ll INF=-4e18;

int m, n, c; bool a[N][N];
int p[N][N]; ll ds[N][N], dc[N][N];

void calc(ll d[N][N]){
    fo(i,1,m-1) fo(j,1,n) if(d[i][j]>INF)
        d[i+1][j-1]=max(d[i+1][j-1], d[i][j]+p[i+1][j-1]),
        d[i+1][j]=max(d[i+1][j], d[i][j]+p[i+1][j]),
        d[i+1][j+1]=max(d[i+1][j+1], d[i][j]+p[i+1][j+1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n>>c;

    fo(i,1,m) fo(j,1,n) cin>>a[i][j];
    fo(i,1,m) fo(j,1,n) cin>>p[i][j];

    memset(ds, -0x3f, sizeof ds);
    memset(dc, -0x3f, sizeof dc);
    
    fo(j,1,n) ds[1][j]=p[1][j];
    calc(ds); ll ans=INF;

    fo(i,1,m) fo(j,1,n) if(a[i][j])
        dc[i][j]=p[i][j];
        
    calc(dc); bool has=0;
    fo(j,1,n) ans=max(ans, ds[m][j]);
    ll ms=INF, mc=INF, me=INF;

    fo(i,1,m) fo(j,1,n) if(a[i][j])
        ms=max(ms, ds[i][j]),
        mc=max(mc, dc[i][j]),
        has=1;
    fo(j,1,n) me=max(me, dc[m][j]);

    if(c>0 && has && ms>INF && me>INF)
        ans=max(ans, ms+me),
        ans=max(ans, ms+(c-1)*mc+me);
    cout<<ans;
}
