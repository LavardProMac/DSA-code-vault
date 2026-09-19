// Source: oj.vnoi.info/problem/gogovoi_868f

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5+5;

int l=1, r=1, a[N], d[N];
ll dp[2][N], v;

ll cost(int L, int R){
    while(l>L) v+=d[a[--l]]++;
    while(r<R) v+=d[a[++r]]++;
    while(l<L) v-=--d[a[l++]];
    while(r>R) v-=--d[a[r--]];
    return v;
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
    cin>>a[1]; dp[0][1]=d[a[1]]++;
    fo(i,2,n) cin>>a[i], dp[1][i]=cost(1, i);
    
    fo(g,2,k) calc(g&1, g, n, g, n);
    cout<<dp[k&1][n];
}
