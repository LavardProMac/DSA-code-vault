#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

vector<pii> a[50005]; ll d[50005];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v, w, s;
    
    cin>>n>>m>>s; q.push({0, s});
    memset(d, 0x3f, sizeof d); d[s]=0;

    fo(i,1,m) cin>>u>>v>>w,
        a[u].emplace_back(v, w),
        a[v].emplace_back(u, w);

    while(!q.empty()){
        auto [du, u]=q.top(); q.pop();
        if(du!=d[u]) continue;

        for(auto [v, w]:a[u]) if(d[v]>d[u]+w)
            d[v]=d[u]+w, q.push({d[v], v});
    }
    ll ans=4e18;
    fo(i,1,n) ans=min(ans, d[i]);
    cout<<(ans>=4e18? -1:ans);
}
