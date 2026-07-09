// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/H

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define f first
#define s second
#define fo(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;

const int N=1e6+5;
const ll INF=1e18;

int n, m, k;
ll dp[100005], d[100005];
vector<pii> g[N];
pair<pii, int> e[N];

void input(){
    fo(i,1,m){
        int u, v, w; cin>>u>>v>>w;
        e[i]={{u, v}, w};
        g[u].emplace_back(w, v);
    }
}

void dijsktra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fo(i,2,n) dp[i]=d[i]=INF;
    
    fo(t,1,k+1){
        while(!pq.empty()) pq.pop();
        fo(i,1,n) if((dp[i]=d[i])<INF)
            pq.push({dp[i], i});

        while(!pq.empty()){
            auto [du,u]=pq.top(); pq.pop();
            if(du!=dp[u]) continue;

            for(auto [w,v]:g[u])
                if(dp[v]>du+w) dp[v]=du+w,
                    pq.push({dp[v], v});
        }
        fo(i,1,m){
            auto [uv,w]=e[i]; auto [u,v]=uv;
            d[v]=min({d[v], dp[v], dp[u]-w});
        }
    }
    cout<<dp[n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    input(); dijsktra();
}
