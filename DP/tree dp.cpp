// Source: vjudge.net/contest/845930#problem/C

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5;

int n, p[N], id[N], l[N], r[N], st[N];
vector<int> g[N]; ll dp[N];

void dfs(int u,int pr,int d,int h,int s){
    for(int v:g[u]) if(v!=pr)
        if(p[v]>h)
            dp[s]=max(dp[s], dp[v]+d+1);
        else dfs(v,u,d+1,h,s);
}

void sub2(){
    fo(i,1,n) dp[i]=-1e18;
    ll ans=dp[id[n]]=0;

    for(int i=n-1; i; --i)
        dfs(id[i],0,0,i,id[i]);

    fo(i,1,n) ans=max(ans, dp[i]);
    cout<<ans;
}

void sub3(){
    int top=0;
    fo(i,1,n){
        while(top && p[st[top]]<p[i]) --top;
        l[i]=top? st[top]:0; st[++top]=i;
    }
    top=0;
    for(int i=n; i; --i){
        while(top && p[st[top]]<p[i]) --top;
        r[i]=top? st[top]:0; st[++top]=i;
    }
    fo(i,1,n) dp[i]=-1e18;
    ll ans=dp[id[n]]=0;

    for(int i=n-1; i>=1; --i){
        int u=id[i];
        if(l[u] && dp[l[u]]>=0)
            dp[u]=max(dp[u], dp[l[u]]+u-l[u]);
        if(r[u] && dp[r[u]]>=0)
            dp[u]=max(dp[u], dp[r[u]]+r[u]-u);
    }
    fo(i,1,n) ans=max(ans, dp[i]);
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int u, v; cin>>n;
    fo(i,1,n) cin>>p[i], id[p[i]]=i;

    fo(i,2,n) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);

    if(n<=5000) sub2();
    else sub3();
}
