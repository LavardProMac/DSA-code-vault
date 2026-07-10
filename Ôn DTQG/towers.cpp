// Source: gspvh2627.contest.codeforces.com/group/GXYpZfKThs/contest/702381/problem/O

#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("towers.inp", "r", stdin);
    freopen("towers.out", "w", stdout);
    int n, x; cin>>n; ll p[n+1];
    
    short a[n+1][n+1], ans=p[0]=0;
    memset(a, -1, sizeof a);
    
    fo(i,1,n) cin>>x,
        p[i]=p[i-1]+x, a[1][i]=1;
    
    fo(l,2,n){
        int k=l-1; short mx=-1;
        fo(r,l,n){
            ll s=p[r]-p[l-1];
            
            while(k && p[l-1]-p[k-1]<s)
                mx=max(mx, a[k--][l-1]);
            if(mx!=-1) a[l][r]=mx+1;
        }
    }
    fo(i,1,n) ans=max(ans, a[i][n]);
    cout<<n-ans;
}
