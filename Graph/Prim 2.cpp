// Source: cses.fi/problemset/task/1675

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
vector<pii> a[N]; bitset<N> d;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v, w; cin>>n>>m;

    fo(i,1,m) cin>>u>>v>>w,
        a[u].emplace_back(v, w),
        a[v].emplace_back(u, w);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); ll ans=0;

    while(!pq.empty()){
        auto [w, u]=pq.top(); pq.pop();
        if(d[u]) continue;
        d[u]=1; ans+=w; --n;

        for(auto [v, c]:a[u]) if(!d[v])
            pq.push({c, v});
    }
    if(n>1) cout<<"IMPOSSIBLE";
    else cout<<ans;
}
