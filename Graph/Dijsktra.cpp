// Source: cses.fi/problemset/task/1671

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

vector<pii> a[100005]; ll d[100005];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v, w;
    
    cin>>n>>m; q.push({0, 1});
    memset(d, 0x3f, sizeof d); d[1]=0;

    fo(i,1,m) cin>>u>>v>>w,
        a[u].emplace_back(v, w);

    while(!pq.empty()){
        auto [du, u]=pq.top(); pq.pop();
        if(du!=d[u]) continue;

        for(auto [v, w]:a[u]) if(d[v]>d[u]+w)
            d[v]=d[u]+w, pq.push({d[v], v});
    }
    fo(i,1,n) cout<<d[i]<<' ';
}
