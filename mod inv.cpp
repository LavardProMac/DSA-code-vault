// Source: vjudge.net/contest/835844#problem/C

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5, M=1e9+7;

int n, q, a[N], sp[N];
ll iv[N*20], ans[N], cur[N];
vector<int> g[N];
map<int, int> mp[N];

void prep(){
    fo(i,2,1e5) if(!sp[i])
        for(int j=i; j<=1e5; j+=i)
            if(!sp[j]) sp[j]=i;

    iv[1]=1;
    fo(i,2,2e6) // mod inv O(N)
        iv[i]=(M-M/i*iv[M%i]%M)%M;
}

ll pw(ll a, ll b, ll r=1){
    for(; b; b>>=1, a=a*a%M)
        if(b&1) r=r*a%M;
    return r;
}

inline void add(int u, int p, int c){
    cur[u]=cur[u]*iv[mp[u][p]+1]%M;
    mp[u][p]+=c;
    cur[u]=cur[u]*(mp[u][p]+1)%M;
}

void dfs(int u,int p){
    cur[u]=1; int x=a[u];
    
    while(x>1){
        int t=sp[x], c=0;
        while(x%t==0) x/=t, ++c;
        add(u, t, c);
    }
    for(int v:g[u]) if(v!=p){
        dfs(v, u);

        if(mp[u].size()<mp[v].size()) // small to large
            swap(mp[u], mp[v]),
            swap(cur[u], cur[v]);

        for(auto [x,c]:mp[v])
            add(u, x, c);
        mp[v].clear();
    }
    ans[u]=cur[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);

    int u, v; cin>>n>>q;
    fo(i,1,n) cin>>a[i];

    fo(i,2,n) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);
    
    prep(); dfs(1, 0);
    while(q--) cin>>u,
        cout<<ans[u]<<' ';
}
