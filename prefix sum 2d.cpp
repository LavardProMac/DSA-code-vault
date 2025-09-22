#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,n) for(int i=j; i<=n; ++i)
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n; cin>>m>>n;
    ll a[m+1][n+1], p[m+1][n+1];
    memset(p, 0, sizeof(p));
    fo(i,1,m) fo(j,1,n) cin>>a[i][j];
    fo(i,1,m) fo(j,1,n)
        p[i][j]=p[i-1][j]+p[i][j-1]-
        p[i-1][j-1]+a[i][j];
    int t, x1, y1, x2, y2; cin>>t;
    while(t--) cin>>x1>>y1>>x2>>y2,
        cout<<p[x2][y2]-p[x1-1][y2]-
        p[x2][y1-1]+p[x1-1][y1-1]<<'\n';
}
