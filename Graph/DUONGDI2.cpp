#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

ll d[200005], d2[200005];
vector<pair<int, int>> a[200005];
priority_queue<pair<ll, int>> pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("DUONGDI2.INP", "r", stdin);
    freopen("DUONGDI2.OUT", "w", stdout);

    memset(d, 0x3f, sizeof d);
    memset(d2, 0x3f, sizeof d2);
    int n, m, u, v, w; d[1]=0;
    cin>>n>>m; pq.push({0, 1});

    fo(i,1,m) cin>>u>>v>>w,
        a[u].emplace_back(v, w),
        a[v].emplace_back(u, u);

    while(!pq.empty()){
        auto [du, u]=pq.top(); pq.pop();
        du=-du;
        if(du>d2[u]) continue;
        for(auto [v, w]:a[u]){
            ll t=w+du;
            if(t<d[v]) swap(t, d[v]),
                pq.push({-d[v], v});
            if(d[v]<t && t<d2[v])
                d2[v]=t, pq.push({-t, v});
        }
    }
    cout<<(d2[n]>2e18? -1:d2[n]);
}
