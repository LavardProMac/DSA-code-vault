#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

ll d[200005];
vector<pair<int, int>> a[200005];
priority_queue<pair<ll, int>> pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("DUONGDI.INP", "r", stdin);
    freopen("DUONGDI.OUT", "w", stdout);

    int n, m, s, t, u, v, w;
    cin>>n>>m>>s>>t; pq.push({0, s});
    memset(d, 0x3f, sizeof d); d[s]=0;
    fo(i,1,m) cin>>u>>v>>w,
        a[u].emplace_back(v, w),
        a[v].emplace_back(u, w);

    while(!pq.empty()){
        auto [du, u]=pq.top(); pq.pop();
        if(-du>d[u]) continue;
        for(auto [v, w]:a[u]) if(d[v]>w-du)
            d[v]=w-du, pq.push({du-w, v});
    }
    cout<<(d[t]>2e18? -1:d[t]);
}
