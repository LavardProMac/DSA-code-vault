// Đếm số xâu t ∈ [s1, s2] t/m t ko chứa substr là bad (MOD 1e9+7)
// |t|=|s1|=|s2|=n, 1 ≤ n ≤ 500

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<n; ++i)
using namespace std;
const int M=1e9+7;

int n, m; string bad, x;
int lps[55], go[55][26];
ll dp[505][55][2];

void build_kmp(){
    fo(i,1,m){
        int j=lps[i-1];
        while(j && bad[i]!=bad[j]) j=lps[j-1];
        
        if(bad[i]==bad[j]) ++j;
        lps[i]=j;
    }
    fo(i,0,m) fo(c,0,26){
        int j=i; char ch='a'+c;
        while(j && bad[j]!=ch) j=lps[j-1];
        
        if(bad[j]==ch) ++j;
        go[i][c]=j;
    }
}

ll solve(int p, int k, bool t){
    if(k==m) return 0;
    if(p==n) return 1;

    ll &res=dp[p][k][t];
    if(res!=-1) return res;
    
    int l=t? x[p]-'a':25; res=0; ++p;

    fo(c,0,l) res=(res+solve(p, go[k][c], 0))%M;
    return res=(res+solve(p, go[k][l], t))%M;
}

ll dfs(const string &st){
    x=st;
    memset(dp, -1, sizeof dp);
    return solve(0, 0, 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s, t; cin>>n>>s>>t>>bad;

    m=bad.size(); build_kmp();
    ll ans=dfs(t); int i=n;
    
    while(i && s[i-1]=='a') s[--i]='z';
    if(i) --s[i-1];

    cout<<(ans-(i? dfs(s):0)+M)%M;
}
