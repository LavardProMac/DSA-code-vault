#include<bits/stdc++.h>
#define ll long long
#define esc(s) return cout<<(s), 0
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
bitset<1000001> dp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    int a[n+1]; dp[0]=1;
    
    fo(i,1,n) cin>>a[i];
    int t=f+s, m=t+1>>1;
    
    fo(i,1,n) dp|=dp<<a[i];
    fo(i,m,t) if(dp[i]) esc(2*i-t);
}
