// Source: hnoj.edu.vn/problem/mst

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

bitset<1005> vs;
ll d[1005][1005], di[1005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;

    while(q--){
        int x1, x2, y1, y2, w;
        cin>>x1>>x2>>y1>>y2>>w;

        d[x1][y1]+=w; d[x2+1][y1]-=w;
        d[x1][y2+1]-=w; d[x2+1][y2+1]+=w;
    }
    fo(i,1,n) fo(j,2,n) d[i][j]+=d[i][j-1];
    fo(j,1,n) fo(i,2,n) d[i][j]+=d[i-1][j];
    
    memset(di, 0x3f, sizeof di);
    ll ans=di[1]=0;

    fo(k,1,n){
        int u=0;
        fo(i,1,n)
            if(!vs[i] && (!u||di[i]<di[u])) u=i;
        vs[u]=1; ans+=di[u];

        fo(v,1,n) if(!vs[v])
            di[v]=min({di[v], d[u][v], d[v][u]});
    }
    cout<<ans;
}
