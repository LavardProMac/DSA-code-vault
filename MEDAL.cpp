#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("MEDAL.INP", "r", stdin);
    freopen("MEDAL.OUT", "w", stdout);

    int n, k, m; cin>>n>>k>>m;
    ll a[n+1]; int j=1, ans=0;

    fo(i,1,n) cin>>a[i];
    sort(a+1, a+n+1);

    if(m==1){
        fo(i,1,n){
            while(j<i && a[i]-a[j]>k) ++j;
            ans=max(ans, i-j+1);
        }
        return cout<<ans, 0;
    }
    int dp[n+1], ans=dp[0]=0;

    fo(i,1,n){
        while(j<i && a[i]-a[j]>k) ++j;
        ans=max(ans, dp[j-1]+i-j+1);
        dp[i]=max(dp[i-1], i-j+1);
    }
    cout<<ans;
}
