// Source: c.tmathcoding.vn/contest/thithu2025/task/3

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct tp{
    int l, r, p;
    bool operator<(const tp& x) const{
        if(r!=x.r) return r<x.r;
        return l<x.l;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; tp a[n+1];
    
    ll dp[n+1]; int e[n+1]; dp[0]=0;
    fo(i,1,n) cin>>a[i].l>>a[i].r>>a[i].p;
    
    sort(a+1, a+n+1);
    fo(i,1,n) e[i]=a[i].r;
    
    fo(i,1,n){
        int j=upper_bound(e+1, e+n+1, a[i].l)-e;
        dp[i]=max(dp[i-1], dp[j-1]+a[i].p);
    }
    cout<<dp[n];
}
