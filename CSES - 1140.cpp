// Name: Projects (Weighted interval scheduling)
// Source: cses.fi/problemset/task/1140

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct tp{
    int l, r, p;
    bool operator<(const tp& x) const{
        return r<x.r;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n; tp a[n+1];
    ll dp[n+1]; int p[n+1]; dp[0]=0;
    
    fo(i,1,n) cin>>a[i].l>>a[i].r>>a[i].p;
    sort(a+1, a+n+1);
    fo(i,1,n) p[i]=a[i].r;
    
    fo(i,1,n){
        ll t=a[i].p; int l=a[i].l;
        int j=lower_bound(p+1, p+n+1, l)-p;
        dp[i]=max(dp[i-1], t+dp[j-1]);
    }
    cout<<dp[n];
}
