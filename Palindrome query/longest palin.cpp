// Source: oj.clue.edu.vn/problem/ptnk_ts10_25_c

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;
int dp[2001][2001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    
    int n=s.size(); s=' '+s;
    fo(i,1,n) dp[i][i]=1;
    
    for(int i=n; i; --i) fo(j,i+1,n)
        if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
        else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
    
    cout<<n-dp[1][n];
}
