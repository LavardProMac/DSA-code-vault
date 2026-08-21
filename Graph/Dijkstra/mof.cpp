// Source: hnoj.edu.vn/problem/mof

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct ed{
    int v, c, d;
};

struct st{
    int d, c, u;
    bool operator>(const st&o) const{
        return d>o.d;
    }
};

int d[105][10005];
vector<ed> g[105];

void dijkstra(int s){
    priority_queue<st, vector<st>, greater<st>> pq;
    memset(d, 0x3f, sizeof d);
    d[s][0]=0; pq.push({0, 0, s});

    while(!pq.empty()){
        auto [du, c, u]=pq.top(); pq.pop();
        if(du!=d[u][c]) continue;

        for(auto [v, x, y]:g[u]){
            int nc=c+x, nd=du+y;
            if(nc<=1e4 && nd<d[v][nc])
                d[v][nc]=nd,
                pq.push({nd, nc, v});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t; cin>>n>>m>>s>>t;
    int u, v, c, D, ans=0, mi=1e9;

    fo(i,1,m) cin>>u>>v>>c>>D,
        g[u].push_back({v, c, D}),
        g[v].push_back({u, c, D});

    dijkstra(s);
    fo(c,0,1e4) if(d[t][c]<mi)
        ++ans, mi=d[t][c];
    cout<<ans;
}
