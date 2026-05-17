#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=2e5+5;
ll p[N], cnt[N]; int a[N], dp[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, j=1; ll s; cin>>n>>s;
    
    fo(i,1,n) cin>>p[i], p[i]+=p[i-1];
    fo(i,1,n){
        while(j<=n && p[j]-p[i-1]<s) ++j;
        a[i]=j;
    }
    for(int i=n; i; --i){
        const int r=a[i];
        dp[i]=dp[i+1]; cnt[i]=cnt[i+1];
        
        if(r<=n){
            int t=dp[r+1]+1; ll k=cnt[r+1]+r-i+1;
            if(t>dp[i] || t==dp[i] && k<cnt[i])
                dp[i]=t, cnt[i]=k;
        }
    }
    cout<<dp[1]<<' '<<cnt[1];
}
