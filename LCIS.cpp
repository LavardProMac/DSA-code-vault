// Name: Longest common increasing subsequence
// Source: csp.vnoi.info/problem/lmh_lcis

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

const int N=5005;
int a[N], b[N], dp[N], t[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n; cin>>m>>n;

    fo(i,1,m) cin>>a[i];
    fo(i,1,n) cin>>b[i];

    fo(i,1,m){
        int mx=0, p=0;
        fo(j,1,n)
            if(a[i]>b[j] && dp[j]>mx)
                mx=dp[j], p=j;

            else if(a[i]==b[j] && mx>=dp[j])
                dp[j]=mx+1, t[j]=p;
    }
    int mx=0, id=0;
    vector<int> v;
    
    fo(i,1,n) if(dp[i]>mx)
        mx=dp[i], id=i;

    while(id)
        v.push_back(b[id]),
        id=t[id];

    reverse(v.begin(), v.end());
    cout<<mx<<'\n';
    for(int i:v) cout<<i<<' ';
}
