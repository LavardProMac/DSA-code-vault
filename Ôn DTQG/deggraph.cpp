// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/F

#include<bits/stdc++.h>
#define ll long long
#define fo(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;

const int N=2225;
const ll INF=4e18;

int n, s[N], tr[N];
ll dp[N];

int deg[N], d[N];
vector<int> pr;
vector<pair<int, int>> ed;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("deggraph.inp", "r", stdin);
    freopen("deggraph.out", "w", stdout);

    cin>>n; int W=n-2;
    fo(i,1,n-1) cin>>s[i];
    fo(i,1,W) dp[i]=-INF;

    fo(k,1,W){
        ll v=1LL*s[k+1]-s[1];
        fo(i,k,W)
            if(dp[i-k]+v>dp[i])
                dp[i]=dp[i-k]+v,
                tr[i]=k;
    }
    cout<<1LL*n*s[1]+dp[W]<<'\n';
    int cur=W, id=0;
    
    while(cur){
        int k=tr[cur];
        deg[++id]=k+1;
        cur-=k;
    }
    while(id<n) deg[++id]=1;
    pr.clear();
    
    fo(i,1,n) fo(j,1,deg[i]-1)
        pr.push_back(i);
    fo(i,1,n) d[i]=deg[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    fo(i,1,n) if(d[i]==1) pq.push(i);

    for(int x:pr){
        int u=pq.top(); pq.pop();
        ed.push_back({u, x});

        --d[u]; --d[x];
        if(d[x]==1) pq.push(x);
    }
    int u=pq.top(); pq.pop();
    int v=pq.top(); pq.pop();

    ed.push_back({u, v});
    cout<<n-1<<'\n';
    
    for(auto &[f,s]:ed)
        cout<<f<<' '<<s<<'\n';
}
