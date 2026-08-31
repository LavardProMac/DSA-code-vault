// Source: oj.clue.edu.vn/problem/dnai_tst_26_c

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1e5+5;
int d[N], deg[N]; bitset<N> del;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y; cin>>n;
    int u[n+1], v[n+1], ans=0;
    vector<int> g[n+1]; queue<int> q;

    fo(i,1,n) cin>>x>>y,
        g[x].push_back(y),
        g[y].push_back(x),
        ++d[u[i]=x], ++d[v[i]=y];
    
    memcpy(deg, d, sizeof d);
    fo(i,1,n) if(deg[i]==1) q.push(i);

    while(!q.empty()){
        int u=q.front(); q.pop();
        del[u]=1;
        for(int v:g[u]) if(!del[v])
            if(--deg[v]==1) q.push(v);
    }
    fo(i,1,n){
        int x=u[i], y=v[i];
        bool cyc=!del[x] || !del[y];
        if(d[x]+d[y]>(cyc? 4:3)) ++ans;
    }
    cout<<ans;
}
