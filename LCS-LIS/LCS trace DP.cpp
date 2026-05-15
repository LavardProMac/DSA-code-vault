// Name: Longest common subsequence
// Source: cses.fi/problemset/task/3403

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=1001;
int a[N], b[N], dp[N][N];
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m; vector<int> v;
    
    fo(i,1,n) cin>>a[i];
    fo(i,1,m) cin>>b[i];
    
    fo(i,1,n) fo(j,1,m) dp[i][j]=
        a[i]==b[j]? dp[i-1][j-1]+1;
        max(dp[i][j-1], dp[i-1][j]);
    
    int t=dp[n][m], i=n, j=m;
    cout<<t<<'\n';
    
    while(i && j)
        if(a[i]==b[j]) v.push_back(a[i--]), --j;
        else if(dp[i-1][j]>dp[i][j-1]) --i;
        else --j;
    
    reverse(v.begin(), v.end());
    for(int i:v) cout<<i<<' ';
}
