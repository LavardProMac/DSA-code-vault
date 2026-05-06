// Name: Weighted interval scheduling
// Source: c.tmathcoding.vn/contest/thithu2025/task/3

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

struct tp{
    int l, r, p; // l: start, r: end, p: profit
    bool operator<(const tp& x) const{
        return r<x.r;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; tp a[n+1];

    // dp[i]: max profit khi xét i công việc đầu
    ll dp[n+1]; int e[n+1]; dp[0]=0;

    fo(i,1,n) cin>>a[i].l>>a[i].r>>a[i].p;
    sort(a+1, a+n+1); // sort theo ending time

    // lưu end vào mảng riêng để tknp nhanh
    fo(i,1,n) e[i]=a[i].r;

    fo(i,1,n){
        // tìm công việc cuối mà có end <= start a[i]
        int j=upper_bound(e+1, e+n+1, a[i].l)-e;

        // hai lựa chọn:
        // 1: không lấy i → dp[i-1]
        // 2: lấy i → dp[j-1] + profit a[i]
        dp[i]=max(dp[i-1], dp[j-1]+a[i].p);
    }
    cout<<dp[n];
}
