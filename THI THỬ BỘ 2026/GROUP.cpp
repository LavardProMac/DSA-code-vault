#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
int a[N], dp[N], cnt[N]; ll p[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("GROUP.INP", "r", stdin);
    freopen("GROUP.OUT", "w", stdout);
    
    int n, j=1; ll s; cin>>n>>s;
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];
    
    fo(i,1,n){
        while(j<=n && p[j]-p[i-1]<s) ++j;
        a[j]=i;
    }
    fo(i,2,n) a[i]=max(a[i], a[i-1]);
    
    fo(i,1,n){
        int x=a[i];
        dp[i]=dp[i-1]; cnt[i]=cnt[i-1];
        
        if(!x--) continue;
        int t=dp[x]+1; ll k=cnt[x]+i-x;
        
        if(t>dp[i] || t==dp[i] && k<cnt[i])
            dp[i]=t, cnt[i]=k;
    }
    cout<<dp[n]<<' '<<cnt[n];
}
