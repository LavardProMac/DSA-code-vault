// BFS O(N+M)

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

unordered_map<int, vector<int>> g;
bitset<N> d;

void bfs(int s){
    queue<int> q;
    q.push(s); d[s]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<' ';

        for(int v:g[u]) if(!d[v])
            d[v]=1, q.push(v);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    
    fo(i,1,m) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);

    fo(i,1,n) if(!d[i]) bfs(i);
}
