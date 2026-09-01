// Source: vjudge.net/contest/845930#problem/C

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=2e5+5;

int n, p[N], id[N], l[N], r[N];
vector<int> g[N]; ll dp[N];

void dfs(int u, int pr, int d, int h, int s){
    for(int v:g[u]) if(v!=pr) if(p[v]>h)
        dp[s]=max(dp[s], dp[v]+d+1);
        else dfs(v, u, d+1, h, s);
}

void sub1(){
    for(int i=n-1; i; --i)
        dfs(id[i], 0, 0, i, id[i]);
}

void sub2(){
    stack<int> st;
    fo(i,1,n){
        while(!st.empty() && p[st.top()]<p[i])
            st.pop();
        l[i]=st.empty()? 0:st.top(); st.push(i);
    }
    stack<int>().swap(st);
    for(int i=n; i; --i){
        while(!st.empty() && p[st.top()]<p[i])
            st.pop();
        r[i]=st.empty()? 0:st.top(); st.push(i);
    }
    for(int i=n-1; i; --i){
        int u=id[i];
        if(l[u] && dp[l[u]]>=0)
            dp[u]=max(dp[u], dp[l[u]]+u-l[u]);
        if(r[u] && dp[r[u]]>=0)
            dp[u]=max(dp[u], dp[r[u]]+r[u]-u);
    }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int u, v; cin>>n;
	fo(i,1,n) cin>>p[i], id[p[i]]=i;

	fo(i,2,n) cin>>u>>v,
        g[u].push_back(v),
        g[v].push_back(u);

    memset(dp, -0x3f, n+1<<3);
    dp[id[n]]=0;
    n<=5000? sub1():sub2();
    cout<<*max_element(dp+1, dp+n+1);
}
