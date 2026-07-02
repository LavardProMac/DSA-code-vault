// Source: lqdoj.edu.vn/problem/longestpath

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
int d[N], dp[N], ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    vector<int> g[n+1]; queue<int> q;

    fo(i,1,m) cin>>u>>v,
        g[u].push_back(v), ++d[v];
    fo(i,1,n) if(!d[i]) q.push(i);

    while(!q.empty()){
        u=q.front(); q.pop();
        ans=max(ans, dp[u]);
        
        for(int v:g[u])
            dp[v]=max(dp[v], dp[u]+1);

        for(int v:g[u])
            if(!--d[v]) q.push(v);
    }
    cout<<ans;
}
