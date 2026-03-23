// Sub1: n <= 1e3
// DP approach

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r; cin>>n>>q;

    int a[n+1], dp[n+1][n+1];
    memset(dp, 0, sizeof dp);
    fo(i,1,n) cin>>a[i];

    for(int i=n; i; --i) fo(j,i+1,n)
        dp[i][j]=dp[i+1][j]+dp[i][j-1]
            -dp[i+1][j-1]+(a[i]>a[j]);

    while(q--) cin>>l>>r,
        cout<<dp[l][r]<<'\n';
}
