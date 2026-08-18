#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int tim, cnt, dfn[N], low[N];
bool ins[N];
vector<int> g[N], st;

void dfs(int u){
    dfn[u]=low[u]=++tim;
    st.push_back(u); ins[u]=1;

    for(int v:g[u])
        if(!dfn[v]) dfs(v),
            low[u]=min(low[u], low[v]);
        else if(ins[v])
            low[u]=min(low[u], dfn[v]);

    if(low[u]==dfn[u]){
        ++cnt;
        while(true){
            int v=st.back();
            st.pop_back();
            ins[v]=0;
            if(v==u) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin>>n>>m;
    
    fo(i,1,m) cin>>u>>v,
        g[u].push_back(v);

    fo(i,1,n) if(!dfn[i]) dfs(i);
    cout<<cnt;
}
