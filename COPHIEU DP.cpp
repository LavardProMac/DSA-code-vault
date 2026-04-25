#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
const int N=1e5; int p[N+1], dp[N+1];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("COPHIEU.INP", "r", stdin);
    freopen("COPHIEU.OUT", "w", stdout);
    
    int n; cin>>n; int a[n+1];
    memset(p, 0x3f, sizeof p);
    
    fo(i,1,n) cin>>a[i],
        p[a[i]]=min(p[a[i]], i);

    dp[0]=p[0];
    fo(i,1,N) dp[i]=min(dp[i-1], p[i]);
    
    fo(i,1,n)
        cout<<max(0, i-dp[a[i]-1])<<' ';
}
