// Source: cses.fi/problemset/task/2086

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=3005;
ll p[N], dp[2][N];

inline ll cost(int l, int r){
    ll w=p[r]-p[l-1]; return w*w;
}

void calc(int id,int l,int r,int L,int R){
    if(l>r) return;
    int m=l+r>>1, g=-1; ll ans=4e18;

    fo(i,L,min(m, R)){
        ll cur=dp[id^1][i-1]+cost(i, m);
        if(cur<ans) ans=cur, g=i;
    }
    dp[id][m]=ans;
    calc(id, l, m-1, L, g);
    calc(id, m+1, r, g, R);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1],
        dp[1][i]=p[i]*p[i];
        
    fo(g,2,k) calc(g&1,1,n,1,n);
    cout<<dp[k&1][n];
}
