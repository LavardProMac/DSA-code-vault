// Source: hnoj.edu.vn/problem/path13

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

ll d[55], dp[55][13][1<<13];
vector<pii> g[55]; int n;

struct st{
    ll d; int u, r, m;
    bool operator>(const st& x) const{
        return d>x.d;
    }
};

ll sub1(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(d, 0x3f, sizeof d);
    pq.push({0, 1}); d[1]=0;

    while(!pq.empty()){
        auto [du, u]=pq.top(); pq.pop();
        if(du>d[u]) continue;
        if(u==n) return du;

        for(auto [v, w]:g[u]) if(d[v]>d[u]+w)
            d[v]=d[u]+w, pq.push({d[v], v});
    }
    return -1;
}

ll sub2(){
    priority_queue<st, vector<st>, greater<st>> pq;
    memset(dp, 0x3f, sizeof dp);
    pq.push({0, 1, 0, 1}); dp[1][0][1]=0;

    while(!pq.empty()){
        auto [du, u, r, m]=pq.top(); pq.pop();
        if(u==n) return du;
        if(du>dp[u][r][m]) continue;

        for(auto [v, w]:g[u]){
            ll nd=du+w; int nr=nd%13;
            if(!(m>>nr&1)){
                int nm=m|1<<nr;
                if(dp[v][nr][nm]>nd)
                    dp[v][nr][nm]=nd,
                    pq.push({nd, v, nr, nm});
            }
        }
    }
    return -1;
}

void solve(){
    int m, u, v, w; cin>>n>>m;
    fo(i,1,n) g[i].clear();

    fo(i,1,m) cin>>u>>v>>w,
        g[u].push_back({v, w});

    string b; cin>>b;
    cout<<(b[0]=='F'?
        sub1():sub2())<<'\n';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}
