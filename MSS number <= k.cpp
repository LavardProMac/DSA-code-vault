// Tính Max sum mảng liên tiếp (cho phép số subarray <= K)
// Đpt: O(N*K)

#include<bits/stdc++.h>
#define ll long long
#define Max(a,b) ({ll v=(b); a=a>v? a:v;})
#define esc(s) return cout<<(s), 0
#define fo(i,j,n) for(int i=j; i<=n; ++i)
#define fd(i,j,n) for(int i=j; i>=n; --i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, x; cin>>n>>k;

    ll dp[k+1][2], ans=dp[0][0]=0;
    fo(i,0,k) dp[i][0]=dp[i][1]=-9e18;

    fo(i,1,n){ cin>>x; fd(j,k,1)
        Max(dp[j][1], dp[j-1][0]),
        Max(dp[j][0], dp[j][1]+=x);
    }
    fo(j,0,k) Max(ans,
        max(dp[j][0], dp[j][1]));
    cout<<ans;
}
